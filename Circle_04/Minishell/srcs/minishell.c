/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:08:22 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/20 19:37:19 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_eof(t_cmd *cmd, char *line)
{
	ft_putendl_fd("\033[38;5;31mminishell exit \033[0m", 1);
	free(line);
	line = NULL;
	ft_exit_minishell(1, &(cmd));
}

void	execute_parsing(t_cmd *cmd, char *line)
{
	ft_putendl_fd("Minishell: Syntax error", 1);
	free_list(&(cmd));
	free(line);
	line = NULL;
}

void	execute_minishell(t_cmd *cmd, char *line)
{
	set_detail_type(&(cmd));

	// 여기에 하기
	// cmd돌면서 str에서 $숫자 하나빼기
	ft_expension(&cmd);
	ft_exec(cmd);
	print_cmdline(&(cmd));
	free_list(&(cmd));
	free(line);
	line = NULL;
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_cmd	*cmd;

	ft_initial(env, ac, av);
	ascii_logo_lol();
	while (1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		line = readline("\033[38;5;41mminishell $> \033[0m");
		cmd = init_cmd();
		if (line == NULL)
			execute_eof(cmd, line);
		add_history(line);
		if (ft_parsing(line, &(cmd)))
		{
			execute_parsing(cmd, line);
			continue ;
		}
		execute_minishell(cmd, line);
	}
	return (0);
}
