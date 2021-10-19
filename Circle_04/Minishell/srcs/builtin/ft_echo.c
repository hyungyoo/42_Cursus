/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:26:25 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/19 20:51:36 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_option(char *str)
{
	int	i;

	i = 0;
	if (str[i++] != '-')
		return (0);
	while (str[i])
		if (str[i++] != 'n')
			return (0);
	return (1);
}

void	ft_print_echo(t_node **cmd)
{
	/*
	 * 모든노드 확인
	 * echo 다음에 나올 변수들
	 * 1. $ 가 나온다면 1. $? 일경우, 
	 *					2. $환경변수
	 * 2. "" 타입이 2 인 경우 , 환경변수
	 *
	 * 3. 출력에 성공했을경우 ' ' 아닐경우 무시
	 */
	while ((*cmd) && (*cmd)->next && (*cmd)->next->type == 12)
	{
		ft_putstr((*cmd)->str);
		ft_putstr(" ");
		(*cmd) = (*cmd)->next;
	}
	if ((*cmd))
		ft_putstr((*cmd)->str);
}

void	ft_echo(t_node **cmd)
{
	int	flag_option;

	flag_option = 0;
	if (!cmd || !*cmd)
		return ;
	if (!((*cmd)->next))
	   return ;
	if (!ft_strcmp((*cmd)->next->str, "$") && !ft_strcmp((*cmd)->next->next->str, "?"))
		printf("%d",(g_info.exit_code));
	(*cmd) = (*cmd)->next;
	if (ft_check_option((*cmd)->str))
	{
		flag_option = 1;
		if ((*cmd)->next)
			(*cmd) = (*cmd)->next;
	}
	ft_print_echo(cmd);
	if (!flag_option)
		ft_putstr("\n");
	g_info.exit_code = 0;
}
