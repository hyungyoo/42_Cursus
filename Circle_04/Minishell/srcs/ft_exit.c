#include "../includes/minishell.h"

void	ft_free_env(t_envp *envp)
{
	t_envp	*tmp;

	if (!envp)
		return ;
	envp->prev->next = NULL;
	while (envp)
	{
		tmp = envp->next;
		free(envp->envp_str);
		free(envp->envp_key);
		free(envp);
		envp = tmp;
	}
}

void	ft_exit(int exit_code)
{
	ft_free_env(g_info.envp);
	rl_clear_history();
	exit(exit_code);
}
