#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	/* readline함수의 리턴값을 저장하기위해 임의로 포인터를 하나 선언한다 */
	char *line;
	t_cmd *cmd;

	/* Init before launch*/
	ft_initial(env, ac, av); /* copy env variable with malloc */
	// cmd = init_cmd();
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
			//free_list(&cmd);
			free(line);
			line = NULL;
			ft_exit_minishell(1, &cmd);
		}
		add_history(line); /* add_history에 저장된 문자열은 up & down 방향키를 이용해 확인할수있다 */
		if (ft_parsing(line, &cmd))
		{
			ft_putendl_fd("Minishell: Syntax error", 1); /* 임시 message */
			/* if there's memory allocations, need to free here */
			free_list(&cmd);
			free(line);
			line = NULL;
			continue ;
		}
		/* set detail types - CMD, BUILTIN_CMD, ARG, FILE etc with parsing elements */
		set_detail_type(&cmd);
		ft_exec(cmd->cmd_start);
		print_cmdline(&cmd);
		free_list(&cmd);
		free(line);
		line = NULL;
	}
	return(0);
}


