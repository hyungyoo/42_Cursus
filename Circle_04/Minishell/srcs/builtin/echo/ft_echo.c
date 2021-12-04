/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:26:25 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/03 09:34:12 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_check_option(char *str)
{
	int	i;

	i = 0;
	if (!str[1])
		return (0);
	if (str[i++] != '-')
		return (0);
	while (str[i])
		if (str[i++] != 'n')
			return (0);
	return (1);
}
/*
void	ft_put_last_env(void)
{
	ft_putstr((g_info.last_env_str + 2));
	ft_putstr("\n");
}
*/
/*
void	ft_echo_type_dolr(t_node **cmd)
{
	if ((*cmd)->flag_nospace == 0)
	{
		ft_putstr("$");
		return ;
	}
	else if ((*cmd)->next && (*cmd)->flag_nospace == 1)
		(*cmd) = (*cmd)->next;
	if ((*cmd)->type == 12)
	{
		if (!ft_strcmp((*cmd)->str, "?"))
			ft_putnbr_fd(g_info.exit_code, 1);
		else if (!ft_strcmp((*cmd)->str, "_"))
			ft_put_last_env();
		else
		{
			if (ft_getenv_echo(g_info.envp, (*cmd)->str))
				ft_putstr(ft_getenv(g_info.envp, (*cmd)->str));
		}
	}
}
void	ft_echo_type_douq(t_node **cmd)
{
	if (((*cmd)->str)[0] == '$')
	{
		if (!ft_strcmp((*cmd)->str + 1, "?"))
			ft_putnbr_fd(g_info.exit_code, 1);
		else if (!ft_strcmp((*cmd)->str + 1, "_"))
			ft_put_last_env();
		else
		{
			if (ft_getenv_echo(g_info.envp, (*cmd)->str + 1))
				ft_putstr(ft_getenv(g_info.envp, (*cmd)->str + 1));
		}
	}
	else
		ft_putstr((*cmd)->str);
}

int	ft_check_sans_espace(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			count++;
		i++;
	}
	return (count);
}
*/
