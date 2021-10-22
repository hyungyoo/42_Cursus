/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:26:22 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/22 18:27:56 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_cd_exec(char *path, char *new_path)
{
	return ;
}

int	main(int argc, char **argv)
{
	char	*path = argv[1];
	char	*new_path = argv[2];

	printf("%s\n", path);
	printf("%s\n", new_path);
}
