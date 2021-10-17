#include "../includes/minishell.h"

void    copy_env(char **env)
{
	/*


	envp ==> minishell.h에서 리스트로 바꾸기
	t_envp	*envp;
	*/

	g_info.envp = env;
	
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
