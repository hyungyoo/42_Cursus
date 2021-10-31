#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	char *line;

	ft_initial(env, ac, av);
	ascii_logo_lol();
	while(1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		line = readline("\033[38;5;41mminishell $> \033[0m");
		g_info.cmd = init_cmd();
		if (line == NULL)
		{
			ft_putendl_fd("\033[38;5;31mminishell exit \033[0m", 1);
			free(line);
			line = NULL;
			ft_exit_minishell(1, &(g_info.cmd));
		}
		add_history(line);
		if (ft_parsing(line, &(g_info.cmd)))
		{
			ft_putendl_fd("Minishell: Syntax error", 1);
			free_list(&(g_info.cmd));
			free(line);
			line = NULL;
			continue ;
		}
		set_detail_type(&(g_info.cmd));
		ft_exec((g_info.cmd)->cmd_start);
		print_cmdline(&(g_info.cmd));
		free_list(&(g_info.cmd));
		free(line);
		line = NULL;
	}
	return(0);
}
