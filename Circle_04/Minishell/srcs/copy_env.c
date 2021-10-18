#include "../includes/minishell.h"

void    copy_env(char **env)
{
	t_envp	*envp;
	
	envp  =NULL;
	ft_node_list_env(&envp, env);
	g_info.envp = envp;
	
}

void	ft_initial_g(void)
{
	g_info.envp = NULL;
}

void	ft_initial(char **env, int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_initial_g();
	copy_env(env);
}
