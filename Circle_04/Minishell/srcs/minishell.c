/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:01:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/11 14:00:11 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(char *str)
{
	str = readline("\033[38;5;41mminishell $> \033[0m");
	if (str == NULL || (ft_strcmp(str, "exit") == 0))
	{	
		free(str);
		str = NULL;
		ft_putstr_fd("minishell exit\n", 1);
		ft_exit();
	}
	add_history(str);
	parsing(str);
	free(str);
	str = NULL;
}

int	main(int ac, char **av, char **env)
{
	char	*str;

	if (ac != 1)
		return (0);
	(void)av;
	str = NULL;
	ft_initial(env);
	while (42)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		minishell(str);
	}
	return (0);
}
