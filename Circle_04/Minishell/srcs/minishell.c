/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:01:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/04 16:28:21 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(char *str)
{
    str = readline("minishell $>");
	if (str == NULL || (ft_strcmp(str, "exit") == 0))
	{
		ft_putstr_fd("minishell exit\n", 1);
		exit (1);
	}
	add_history(str);
	parsing(str);
	free(str);
	str = NULL;
}

int	main(int ac, char **av, char **env)
{
    char *str;

	if (ac != 1)
		return (0);
	(void)av;
    str = NULL;

	ft_initial(env);
    while(1)
    {   
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		minishell(str);
	}
	return (0);
}
