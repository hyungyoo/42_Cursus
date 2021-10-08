/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:01:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/08 08:12:08 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{

	//str = readline("\033[38;5;41mminishell $>\033[0m");
	//free(str);
	char *str = NULL;
	str = malloc(sizeof(char) * 5);
	int i = 0;
	while (i < 4)
	{
			str[i] = 'a';
			i++;
	}
	str[i] = '\0';
	printf("%s\n", str);
	char *tmp = str;
	add_history("a");
	rl_clear_history();
	free(str);
	return (0);
}
