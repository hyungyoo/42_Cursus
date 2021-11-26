/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:00:19 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/26 18:03:10 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_error_message_string_arg(t_node *node, t_cmd *cmd)
{
	ft_putendl_fd("\033[38;5;31mexit\033[0m", 2);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd((node)->str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	g_info.exit_code = 255;
	ft_exit_with_message(cmd);
}

void	ft_exit_builtin(t_node **cmd, t_cmd *cmd_start)
{
	g_info.exit_code = 0;
	if (ft_check_pipe_before_exit(cmd_start))
		return ;
	//if (!((*cmd)->next))
	//	ft_exit_with_message(cmd_start);
	//printf("1");
	(*cmd) = (*cmd)->next;
	while ((*cmd) && !ft_not_type(*cmd))
		(*cmd) = (*cmd)->next;
	if (ft_check_num_exit((*cmd)->str))
	{
		if ((*cmd)->next)
		{
			ft_putendl_fd("\033[38;5;31mexit\033[0m", 2);
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			ft_exit_minishell(1, &cmd_start);
		}
		g_info.exit_code = ft_set_exit_code((*cmd)->str);
		ft_exit_minishell(g_info.exit_code, &cmd_start);
	}
	if (!ft_check_num_exit((*cmd)->str))
		ft_error_message_string_arg((*cmd), cmd_start);
}
