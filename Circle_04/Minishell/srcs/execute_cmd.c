#include "../includes/minishell.h"

char	*get_path(char *str)
{
	char	**split_path;
	int		i;
	char	*tmp1;
	char	*tmp2;

	i = -1;
	if (!ft_strncmp(str, "/", 1))
		return (ft_strdup(str));
	split_path = ft_split(ft_getenv(g_info.envp, "PATH"), ':');
	while (split_path[++i])
	{
		tmp1 = ft_strjoin(split_path[i], "/");
		tmp2 = ft_strjoin(tmp1, str);
		free(tmp1);
		if (access(tmp2, F_OK | X_OK) == 0)
		{
			free_tab2(split_path);
			return (tmp2);
		}
		free(tmp2);
	}
	free_tab2(split_path);
	return (ft_strdup(str));
}

int	count_arg(t_node *node)
{
	int	size;

	size = 0;
	while (node && node->type != PIPE)
	{
		if (node->flag_nospace == 0)
			size++;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (size);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;
	int		size_str;
	int		i;
	int		index;

	ret = NULL;
	if (!s1)
		ret = ft_strdup((s2));
	else
	{
		size_str = ft_strlen(s1) + ft_strlen(s2);
		ret = (char *)malloc(sizeof(char) + size_str + 1);
		if (!ret)
			return (NULL);
		index = 0;
		i = 0;
		while (s1[index])
			ret[i++] = s1[index++];
		index = 0;
		while (s2[index])
			ret[i++] = s2[index++];
		ret[i] = '\0';
		free(s1);
	}
	return (ret);
}

char	*ft_arg(t_node **node)
{
	char	*ret;

	ret = NULL;
	if (!node || !*node)
		return (NULL);
	while (*node && (*node)->flag_nospace == 1)
	{
		ret = ft_strjoin_free(ret, (*node)->str);
		if ((*node)->next)
			(*node) = (*node)->next;
	}
	if ((*node))
		ret = ft_strjoin_free(ret, (*node)->str);
	return (ret);
}

char	**get_arg(t_node *node)
{
	char	**path_arg;
	int		i;
	int		num_arg;

	i = 0;
	if (!node)
		return (NULL);
	num_arg = count_arg(node);
	path_arg = (char **)malloc(sizeof(char *) * (num_arg + 1));
	if (!path_arg)
		return (NULL);
	while (node && i < num_arg)
	{
		if (node->flag_nospace == 1)
			path_arg[i] = ft_arg(&node);
		else if (node->flag_nospace == 0)
			path_arg[i] = ft_strdup(node->str);
		if (node->next)
			node = node->next;
		i++;
	}
	path_arg[i] = NULL;
	return (path_arg);
}

void	ft_error_message(char *path, char **argv, char **env)
{
	ft_putstr("Minishell: ");
	ft_putstr(path);
	ft_putstr(": command not found\n");
	free(path);
	free_tab2(argv);
	free_tab2(env);
	g_info.exit_code = 1;
}

int	ft_error_message_no_path(char **argv, char **env)
{
	if (!ft_strncmp(argv[0], "/", 1))
		return (1);
	else if (!ft_getenv(g_info.envp, "PATH"))
	{
		ft_putstr("Minishell: ");
		ft_putstr(argv[0]);
		ft_putstr(": command not found\n");
		free_tab2(argv);
		free_tab2(env);
		return (0);
	}
	else
		return (1);
}

void	ft_execmd_child(t_node *node)
{
	char	*path;
	char	**argv;
	char	**env;
	
	env = ft_array_double_env();
	argv = get_arg(node);
	path = get_path(argv[0]);
	execve(path, argv, env);
}

int	ft_check_path_exec(t_node *node)
{
	char	*path;
	char	**argv;
	char	**env;
	int		flag_access;
	
	if (!node)
		return (0);
	env = ft_array_double_env();
	argv = get_arg(node);
	if (!ft_error_message_no_path(argv, env))
		return (0);
	if (argv[0])
		path = get_path(argv[0]);
	flag_access = access(path, F_OK | X_OK);
	if (flag_access == -1)
	{
		ft_error_message(path, argv, env);
		return (0);
	}
	free_tab2(argv);
	free_tab2(env);
	free(path);
	return (1);
}

int	ft_execmd(t_node *node)
{
	int		status;


	if (!ft_check_path_exec(node))
		return (EXIT_SUCCESS);
	g_info.pid_child = fork();
	if (g_info.pid_child == 0)
		ft_execmd_child(node);
	else if (g_info.pid_child > 0)
	{
		waitpid(g_info.pid_child, &status, 0);
		g_info.pid_child = 0;
	}
	else if (g_info.pid_child < 0)
		return (-1);
	return (EXIT_SUCCESS);
}
