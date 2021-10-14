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
		if (line == NULL || (ft_strcmp(line, "exit") == 0))
		{
			ft_putendl_fd("\033[38;5;31mminishell exit \033[0m", 1);
			free_tab2(g_info.env);
			free_list(&cmd);
			free(line);
			line = NULL;
			ft_exit(1);
		}
		add_history(line); /* add_history에 저장된 문자열은 up & down 방향키를 이용해 확인할수있다 */
		/* 
		** here : parsing process with str
		*/
		if (ft_parsing(line, &cmd))
		{
			ft_putendl_fd("Minishell: Syntax error", 1); /* 임시 message */
			/* if there's memory allocations, need to free here */
			free_list(&cmd);
			free(line);
			line = NULL;
			continue ;
		}
		print_cmdline(&cmd);
		free_list(&cmd);
		free(line);
		line = NULL;
	}
	// free_tab2(g_info.env);
	return(0);
}




	// void	classify(struct dirent *ent)
// {
// 	printf("%s\t", ent->d_name);
// 	if (ent->d_type == DT_BLK)
// 		printf("Block Device\n");
// 	else if (ent->d_type == DT_CHR)
// 		printf("Character Device\n");
// 	else if (ent->d_type == DT_DIR)
// 		printf("Directory\n");
// 	else if (ent->d_type == DT_LNK)
// 		printf("Symbolic Link\n");
// 	else if (ent->d_type == DT_REG)
// 		printf("Regular File\n");
// 	else if (ent->d_type == DT_SOCK)
// 		printf("Unix Domain Socket\n");
// 	else
// 		printf("Unknown Type File\n");
// }


	// DIR *test;
	// struct dirent *file;
	// int tmp;

	// test = opendir("/Users/keulee/mygithub/minishell");
	// if (!test)
	// {
	//     write(1, "error\n", 6);
	//     return (1);
	// }
	// while (1)
	// {
	//     tmp = errno;
	//     file = readdir(test);
	//     if (!file && tmp != errno)
	//     {
	//         write(1, "error\n", 6);
	//         break;
	//     }
	//     if (!file)
	//         break;
	//     classify(file);
	// }
	// closedir(test);
	// return (0);

	
	/* 함수종료 */