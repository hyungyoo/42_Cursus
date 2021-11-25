/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_list_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:46:59 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/18 12:07:30 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_check_redir_str(char *str)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "<") || !ft_strcmp(str, "<<")
		|| !ft_strcmp(str, ">") || !ft_strcmp(str, ">>"))
		return (1);
	return (0);
}

int	ft_check_redir_type(t_node *node)
{
	if (node->type == LEFT || node->type == DLEFT
		|| node->type == RIGHT || node->type == DRIGHT)
		return (1);
	return (0);
}

char	*ft_getenv(t_envp *envp, char *key)
{
	t_envp	*tmp;

	tmp = NULL;
	tmp = envp->prev;
	while (tmp != envp)
	{
		if (!ft_strcmp(envp->envp_key, key))
			return (envp->envp_value);
		envp = envp->next;
	}
	if (!ft_strcmp(envp->envp_key, key))
		return (envp->envp_value);
	return (NULL);
}

char	*ft_getenv_echo(t_envp *envp, char *key)
{
	t_envp	*tmp;

	if (!ft_strcmp(key, "PWD") && g_info.flag_pwd == 1)
		return (NULL);
	tmp = NULL;
	tmp = envp->prev;
	while (tmp != envp)
	{
		if (!ft_strcmp(envp->envp_key, key))
			return (envp->envp_value);
		envp = envp->next;
	}
	if (!ft_strcmp(envp->envp_key, key))
		return (envp->envp_value);
	return (NULL);
}

int	ft_size_key(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}
