/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:01:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/09/30 17:45:41 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler(int signum)
{
	if (signum != SIGINT)
		return ;
    write(STDOUT_FILENO, "\n", 1);
    //if (rl_on_new_line() == -1)
    //   exit(1);
    //rl_replace_line("", 1);
    //rl_redisplay();
}

int	main(int ac, char **av, char **env)
{
    char *str;

	if (ac != 1)
		return (0);
	(void)av;
    str = NULL;

	ft_initial(env);
    signal(SIGINT, handler);
    while(1)
    {
        str = readline("minishell $>");
		if (str == NULL || (ft_strcmp(str, "exit") == 0))
		{
			ft_putstr_fd("minishell exit\n", 1);
			exit (1);
		}
        //add_history(str);
		parsing(str);
		free(str);
		str = NULL;
	}
	return (0);
}
