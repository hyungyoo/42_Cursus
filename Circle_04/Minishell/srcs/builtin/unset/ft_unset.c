/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:10:13 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/01 22:23:14 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_chercher_key(t_envp *envp, char *arg)
{
	t_envp	*tmp;

	if (!envp || !arg)
		return (0);
	tmp = envp->prev;
	while (envp != tmp)
	{
		if (!ft_strcmp(envp->envp_key, arg))
			return (1);
		envp = envp->next;
	}
	if (!ft_strcmp(envp->envp_key, arg))
		return (1);
	return (0);
}

void	ft_free_one_node(t_envp *envp, char *arg)
{
	while (envp)
	{
		if (!ft_strcmp((envp)->envp_key, arg))
		{
			(envp)->next->prev = (envp)->prev;
			(envp)->prev->next = (envp)->next;
			free((envp)->envp_key);
			free((envp)->envp_value);
			free((envp)->envp_str);
			free((envp));
			return ;
		}
		(envp) = (envp)->next;
	}
}

void	ft_error_message_unset(char *str)
{
	ft_putstr_fd("minishell: unset: ", 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	g_info.exit_code = 1;
}

int	check_error_unset(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i == 0 && ft_is_digit(str[i])) || str[i] == '=')
		{
			ft_error_message_unset(str);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_unset_exec(t_node **cmd)
{
	char	**split_arg;
	int		i;

	i = 0;
	split_arg = ft_array_double_export(*cmd);
	while (split_arg[i])
	{
		if (check_error_unset(split_arg[i])
			&& ft_chercher_key(g_info.envp, split_arg[i]))
			ft_free_one_node(g_info.envp, split_arg[i]);
		i++;
	}
	free_tab2(split_arg);
}
