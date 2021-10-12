/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:26:07 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/12 13:16:45 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
 * check_quote et check_dquote
 * prendre les split_cmd et les verifier
 * si dquote ou quote ne sont pas ferme,
 * return 0
 * ou bine 1
 */
int	ft_check_dquote(char **split_cmd)
{
	int	i;

	i = 0;
	while (split_cmd[i])
	{
		if (ft_verifier_dquote(split_cmd[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
 * prendre str venant de function readline
 * et avec funtion ft_split, split avec ' '
 * ensuite, avec function ft_split_cmd,
 * reconstruire et split avec multiple cmd(| < << > >>)
 * return 0 si y a probleme
 * sinon return 1
 */
int	ft_parsing_cmd(char *str)
{
	char	**split_str;

	split_str = ft_split(str, ' ');
	g_info.split_cmd = ft_split_cmd(split_str);
	if (!ft_check_dquote(g_info.split_cmd))
	{
		ft_free_double(g_info.split_cmd);
		return (0);
	}
	return (1);
}
