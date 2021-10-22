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
	split_path = ft_split(getenv("PATH"), ':');
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

int ft_execmd(t_node *node)
{
	/* path 얻는 함수 - malloc*/
	char    *path;
	/* cmd + arg 얻는 함수 - malloc*/
	char    **argv;
    int     flag;
    pid_t   pid;
    int     status;

    /* fork here*/ 
    pid = fork();
    g_info.fork_flag = 1;
    path = get_path(node);
	argv = get_arg(node);

    if (pid < 0)
        return (-1) ;
    else if (pid == 0)
    {
        flag = execve(path, argv, g_info.env);
        if (flag == -1)
        {
            printf("Minishell: %s: command not found\n", argv[0]);
            free(path);
            free_tab2(argv);
            exit(127);
        }
    }
    else
    { /*pid > 0*/
        wait(&status);
        // printf("done\n");
    }
    // else if (pid > 0)
    // {
        // free(path);
        // free_tab2(argv);
		// g_info.flag_read = 0;
        // return (1);
    // }
	return (EXIT_SUCCESS);
}
