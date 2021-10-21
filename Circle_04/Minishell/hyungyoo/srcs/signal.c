#include "../includes/minishell.h"

void	handler(int signum)
{
	if (signum == SIGINT || signum == SIGQUIT)
	{
		printf("\r");
		rl_on_new_line();
		rl_redisplay();
		printf("  \b\b");
		if (signum == SIGINT)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	return ;
}
