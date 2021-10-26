#include "../includes/minishell.h"

char	*get_path(t_node *node)
{
	char	**split_path;
	int		i;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	if (!node)
		return (NULL);
	if (!ft_strncmp(node->str, "/", 1))
	{
		if (access(node->str, F_OK | X_OK) == 0)
			return (node->str);
	}
	////////////////////////////////////////////////////////////////
	// split_path = ft_split(getenv("PATH"), ':');
	split_path = ft_split(ft_getenv(g_info.envp, "PATH"), ':');
	if (!split_path)
		return (NULL);
	//////////////////////////////////////////////////////////////////
	while (split_path[i])
	{
		tmp1 = ft_strjoin(split_path[i], "/");
		tmp2 = ft_strjoin(tmp1, node->str);
		free(tmp1);
		if (access(tmp2, F_OK | X_OK) == 0)
		{
			free_tab2(split_path);
			return (tmp2);
		}
		free(tmp2);
		i++;
	}
	free_tab2(split_path);
	return (NULL);
}

int    count_arg(t_node *node)
{
    int     size;
    t_node  *tmp;

    size = 1;
    tmp = node;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (tmp->type == PIPE)
            break;
        size++;
    }
    return (size);
}

char    **get_arg(t_node *node)
{
    char    **path_arg;
    t_node  *tmp;
    int     i;

    i = 0;
    if (!node)
        return (NULL);
    tmp = node;
    path_arg = malloc(sizeof(char *) * (count_arg(node) + 1)); /* NULL terminated count */
    // printf("size ; %d\n", count_arg(node));
    if (!path_arg)
        return (NULL); /* Protection */
    while (tmp != NULL && i < count_arg(node))
    {
        // printf("tmp->str : %s\n", tmp->str);
        // printf("i : %d\n", i);
        path_arg[i] = malloc(sizeof(char) * (ft_strlen(tmp->str) + 1));
        ft_strcpy(path_arg[i], tmp->str);
        i++;
        if (tmp->next)
            tmp = tmp->next;
        if (tmp->type == PIPE)
            break;
    }
    path_arg[i] = NULL;
	return (path_arg);
}

// char    *update_cmdline(char *first, char *second)
// {
//     char *tmp1;

// 	tmp1 = ft_strjoin(first, second);
// 	if (*first && first)
// 	{
// 		free(first);
// 		first = NULL;
// 	}
// 	return (tmp1);
// }

// int     is_quote_arg(t_node *node)
// {
//     if (node->type == ARG || node->type == SINQ || node->type == DOUQ)
//         return (0);
//     return (1);
// }

// void	parsing_the_rest(t_cmd **cmd, t_node *node)
// {
// 	if (node->type == CMD)
// 		insert_node(cmd, CMD, node->str);
// 	else if (node->type == SINQ)
// 		insert_node(cmd, SINQ, node->str);
// 	else if (node->type == DOUQ)
// 		insert_node(cmd, DOUQ, node->str);
// 	else if (node->type == LEFT)
// 		insert_node(cmd, LEFT, node->str);
// 	else if (node->type == DLEFT)
// 		insert_node(cmd, DLEFT, node->str);
// 	else if (node->type == RIGHT)
// 		insert_node(cmd, RIGHT, node->str);
// 	else if (node->type == DRIGHT)
// 		insert_node(cmd, DRIGHT, node->str);
// 	else if (node->type == DOLR)
// 		insert_node(cmd, DOLR, node->str);
// 	else
// 		insert_node(cmd, ARG, node->str);
// }

// void    set_cmdline(t_node **node, t_cmd **cmdline)
// {
//     char    *cmd_str;
//     char    *arg_str;

//     cmd_str = NULL;
//     arg_str = NULL;
//     if (!(*node))
//         return ;
//     while ((*node) && (*node)->type != PIPE)
//     {
//         if ((*node)->type == CMD && (*node)->flag_nospace == 1)
//         {
//             while ((*node)->next && (*node)->flag_nospace != 0 && (*node)->type != PIPE)
//             {
//                 if (!cmd_str)
//                     cmd_str = ft_strdup((*node)->str);
//                 else
//                     cmd_str = update_cmdline(cmd_str, (*node)->str);
//                 if ((*node)->next)
//                     (*node) = (*node)->next;
//             }
//             cmd_str = update_cmdline(cmd_str, (*node)->str);
//             insert_node(cmdline, CMD, cmd_str);
//         }
//         else if (!is_quote_arg((*node)) && (*node)->flag_nospace == 1)
//         {
//             while ((*node)->next && (*node)->flag_nospace != 0 && (*node)->type != PIPE)
//             {
//                 if (!arg_str)
//                     arg_str = ft_strdup((*node)->str);
//                 else
//                     arg_str = update_cmdline(arg_str, (*node)->str);
//                 if ((*node)->next)
//                     (*node) = (*node)->next;
//             }
//             arg_str = update_cmdline(arg_str, (*node)->str);
//             insert_node(cmdline, ARG, arg_str);
//         }
//         else
//             parsing_the_rest(cmdline, (*node));
//         if ((*node)->next)
//             (*node) = (*node)->next;
//         else
//             break ;
//     }
// }

// int    check_nospace_flag(t_node *node, t_cmd *cmdline)
// {
//     t_node  *tmp;
//     int     nospace;
//     int     op_word;

//     nospace = 0;
//     op_word = 0;
//     if (!node)
//         return (1);
//     tmp = node;
//     while (tmp->next && tmp->type != PIPE)
//     {
//         if (tmp->flag_nospace == 1)
//             nospace = 1;
//         if (!is_operation_word(tmp))
//             op_word = 1;
//         if (tmp->next)
//             tmp = tmp->next;
//         else
//             break ;
//     }
//     tmp = node;
//     if (nospace && !op_word)
//     {
//         set_cmdline(&tmp, &cmdline);
//         return (0);
//     }
//     return (1);
// }

int ft_execmd(t_node *node)
{
	/* path 얻는 함수 - malloc*/
	char    *path;
	/* cmd + arg 얻는 함수 - malloc*/
	char    **argv;
    pid_t   pid;
    int     status;
    // t_node *tmp;
    /* 띄워쓰기에 따라 커맨드라인 다시 찾기 - malloc */
    // char    *cmdline;
    // t_cmd   *cmdline;
    
    /* fork here*/ 
    g_info.fork_flag = 1;
    // cmdline = init_cmd();
    // if (!check_nospace_flag(node, cmdline))
    // {
        // print_cmdline(&cmdline);
        /*path,arg 다시 파싱*/
        // path = get_path(cmdline->cmd_start);
        // argv = get_arg(cmdline->cmd_start);
        // free_list(&cmdline);
    // }
    // else
    // {
        path = get_path(node);
	    argv = get_arg(node);
    // }
    // printf("path : %s\n", path);
    // int i = 0;
    // while (argv[i])
    // {
    //     printf("argv[%d] : %s\n", i, argv[i]);
    //     i++;
    // }    
    pid = fork();
    if (pid < 0)
        return (-1);
    else if (pid == 0)
    {
        // if(!path)
        // {
        //     printf("Minishell: %s: command not found\n", argv[0]);
        //     free(path);
        //     free_tab2(argv);
        //     exit(127);
        // }
        if (execve(path, argv, g_info.env) == -1)
        {
            // i = 1;
            // while (argv[i])
                // printf("Minishell: %s: %s: No such file or directory\n", argv[0], argv[i++]);
            printf("Minishell: %s: command not found\n", argv[0]);
            free(path);
            free_tab2(argv);
            g_info.exit_code = 1;
            exit(1);
        }
    }
    else /*pid > 0*/
    {
        wait(&status);
        g_info.pid_child = 0;
    }
    free(path);
    free_tab2(argv);
	return (EXIT_SUCCESS);
}
