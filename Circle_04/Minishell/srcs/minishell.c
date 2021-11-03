#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	char *line;
	t_cmd	*cmd;

	ft_initial(env, ac, av);
	ascii_logo_lol();
	while(1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		line = readline("\033[38;5;41mminishell $> \033[0m");
		cmd = init_cmd();
		if (line == NULL)
		{
			ft_putendl_fd("\033[38;5;31mminishell exit \033[0m", 1);
			free(line);
			line = NULL;
			ft_exit_minishell(1, &(cmd));
		}
		add_history(line);
		if (ft_parsing(line, &(cmd)))
		{
			ft_putendl_fd("Minishell: Syntax error", 1);
			free_list(&(cmd));
			free(line);
			line = NULL;
			continue ;
		}
		set_detail_type(&(cmd));
		ft_exec(cmd);
		print_cmdline(&(cmd));
		free_list(&(cmd));
		free(line);
		line = NULL;
	}
	return(0);
}
