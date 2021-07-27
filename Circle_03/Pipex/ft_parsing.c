#include "pipex.h"

void	ft_free_parsing(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

char	**ft_path_parsing(char **envp)
{
	int		i;
	char	**path_parsing;

	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "PATH=", 5)))
			break ;
		i++;
	}
	path_parsing = ft_split(&envp[i][5]);
	return (path_parsing);
}

int	ft_size_parsing(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
