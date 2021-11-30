/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/30 19:24:08 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_export_set_node(char **str)
{
	char	*key_tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		key_tmp = ft_key(str[i]);
		if (ft_getenv(g_info.envp, key_tmp))
			ft_update_env(g_info.envp, str[i], key_tmp);
		else
			ft_ajouter_node(&(g_info.envp), ft_new_node_env(str[i]));
		free(key_tmp);
		i++;
	}
}

void	empty_error_message(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": `': not a valid identifier\n", 2);
}

void	ft_export(t_node **cmd)
{
	char	**str;

	g_info.exit_code = 0;
	if (!cmd || !*cmd)
		return ;
	else if (!ft_check_arg(*cmd) && !((*cmd)->flag_emptystr))
	{
		ft_export_env();
		return ;
	}
	if ((*cmd)->flag_emptystr)
	{
		empty_error_message("export");
		g_info.exit_code = 1;
		if (!((*cmd)->next))
			return ;
	}
	(*cmd) = (*cmd)->next;
	str = ft_array_double_export(*cmd);
	str = ft_new_array_export(str, ft_check_all(str));
	ft_export_set_node(str);
	free_tab2(str);
}
