/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:01:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/08 16:57:50 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

typedef struct s_ex
{
	int	i;
	char c;
}				t_ex;

void	ft_init(t_ex *str)
{
	str->i = 5;
	str->c = 'c';
}

int	main(int argc, char **argv, char **env)
{

	//str = readline("\033[38;5;41mminishell $>\033[0m");
	//free(str);
	
	//t_ex *str = NULL;
	//str = (t_ex*)malloc(sizeof(t_ex));
	//ft_init(str);
	//printf("printf=> %d, %c\n", str->i, str->c);
	
	char **str;
	str = (char **)malloc(sizeof(char *) * 3 + 1);
	str[3] = NULL;
	str[0] = (char *)malloc(sizeof(char) * 5);
	str[1] = (char *)malloc(sizeof(char) * 3);
	str[2] = (char *)malloc(sizeof(char) * 5);
	str[0][4] = '\0';
	str[1][2] = '\0';
	str[2][4] = '\0';
	
	str[0][0] = 'e';
	str[0][1] = 'c';
	str[0][2] = 'h';
	str[0][3] = 'o';

	str[1][0] = '-';
	str[1][1] = 'n';
	str[2][0] = 'h';
	str[2][1] = 'e';
	str[2][2] = 'r';
	str[2][3] = 'e';


	execve("/bin/echo", str, env);
	return (0);
}
