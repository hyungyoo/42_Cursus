/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:26:25 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/30 18:21:24 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_type_douq_with_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			ft_print_env_quote(str, &i);
		else
			ft_putchar(str[i]);
		i++;
	}
}

void	ft_type_douq_sans_espace(t_node **cmd)
{
	char	**split_str;

	split_str = NULL;
	if (ft_check_quote((*cmd)->str))
		ft_type_douq_with_quote((*cmd)->str);
	else
	{
		split_str = ft_split((*cmd)->str, '$');
		ft_echo_type_douq_sans_espace(split_str, (*cmd)->str);
		free_tab2(split_str);
		split_str = NULL;
	}
}

int	ft_not_type(t_node *node)
{
	if (node->type == LEFT || node->type == FILE
		|| node->type == DLEFT || node->type == RIGHT
		|| node->type == DRIGHT || node->type == PIPE)
		return (0);
	return (1);
}

void	ft_print_echo(t_node **cmd)
{
	while (*cmd && ((*cmd)->type != PIPE))
	{
		if (check_pwd(cmd))
			(*cmd) = (*cmd);
		if (ft_not_type((*cmd)) && !(g_info.flag_pwd == 1
				&& !ft_strcmp((*cmd)->str, ft_getenv(g_info.envp, "PWD"))))
			ft_putstr((*cmd)->str);
		if (ft_not_type((*cmd)) && ft_not_type((*cmd)->prev)
			&& (*cmd)->flag_nospace == 1)
			ft_putstr("");
		else if (ft_not_type(*cmd) && (*cmd)->next
			&& (*cmd)->next->type != PIPE)
			ft_putstr(" ");
		if ((*cmd)->next)
			(*cmd) = (*cmd)->next;
		else
			return ;
	}
}

void	ft_echo(t_node **cmd)
{
	int	flag_option;

	flag_option = 0;
	g_info.exit_code = 0;
	if (!cmd || !*cmd)
		return ;
	if (!((*cmd)->next))
		return ;
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
}
