#include "../includes/minishell.h"

void	ft_exit(int exit_code)
{
	rl_clear_history();
	exit(exit_code);
}
