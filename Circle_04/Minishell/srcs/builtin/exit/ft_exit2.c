/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:00:19 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/26 18:54:46 by hyungyoo         ###   ########.fr       */
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
	ft_exit_minishell(g_info.exit_code, &cmd);
}

void	ft_error_message_many_arg(void)
{
	ft_putendl_fd("\033[38;5;31mexit\033[0m", 2);
	ft_putstr_fd("minishell: exit", 2);
	ft_putstr_fd(": too many arguments\n", 2);
	g_info.exit_code = 1;
}

void	ft_exit_builtin(t_node **cmd, t_cmd *cmd_start)
{
	char	**array_exit;

	if (ft_check_pipe_before_exit(cmd_start))
		return ;
	g_info.exit_code = 0;
	if (!((*cmd)->next))
		ft_exit_with_message(cmd_start);
	(*cmd) = (*cmd)->next;
	array_exit = ft_array_double_export(*cmd);
	if (!ft_check_num_exit(array_exit[0]))
		ft_error_message_string_arg(*cmd, cmd_start);
	else if (ft_tab_size(array_exit) == 1 && ft_check_num_exit(array_exit[0]))
	{
		g_info.exit_code = ft_set_exit_code(array_exit[0]);
		ft_exit_with_message(cmd_start);
	}
	else if (ft_tab_size(array_exit) > 1)
		return (ft_error_message_many_arg());
}
