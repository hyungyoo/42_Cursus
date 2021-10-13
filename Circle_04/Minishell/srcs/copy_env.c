#include "../includes/minishell.h"

void    copy_env(char **env)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (env[count])
		count++;
	g_info.env = (char **)malloc(sizeof(char *) * (count + 1));
	if (!g_info.env)
		return ;
	while (env[i])
	{
		g_info.env[i] = ft_strdup(env[i]);
		i++;
	}
	g_info.env[i] = NULL;    
}

void	ft_initial_g(void)
{
	g_info.env = NULL;
}

void	ft_initial(char **env, int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_initial_g();
	copy_env(env);
}