/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:01:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/09/30 17:14:50 by hyungyoo         ###   ########.fr       */
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

void    copy_env(char **env)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (env[count])
        count++;
    g_info.env = (char **)malloc(sizeof(char *) * (count + 1));
    while (env[i])
    {
        g_info.env[i] = ft_strdup(env[i]);
        i++;
    }
    g_info.env[i] = NULL;        
}

int	main(int ac, char **av, char **env)
{
    char *str;

	if (ac != 1)
		return (0);
	(void)av;
    str = NULL;
    g_info.env = NULL;

    copy_env(env);
	g_info.quit_quote = 0;

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
