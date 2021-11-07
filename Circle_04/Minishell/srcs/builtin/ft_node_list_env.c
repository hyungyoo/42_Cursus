/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_list_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:46:59 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/07 16:31:30 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_redir_str(char *str)
{
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

/*
int	ft_redir_passe_node(t_node **node)
{
	 * 1. 모든 노드를 다 돌면서, > 다음에 다음거가있는지 없으면 리턴 0
	 * 포인터하나보내고 여기로돌아왓을떄, 과연 노드가 움직이는지 안옴우직여있는지 확인
	 * 다 돌고 돌아와서  이건다른곳에해서 ft_redir_pass랑 합치기
	 *
	 * 2. 다이렉션일떄는, 들어와서, 바로 다음다음으로 들어가도록 노드를 새로 반환

	// 그리고 꼭 그거 만들어서 실행파일도 되도록 만들기
}
*/

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

char	*ft_key(char *env)
{
	char	*key;
	int		size_key;

	key = NULL;
	size_key = ft_size_key(env);
	key = (char *)malloc(sizeof(char) * size_key + 1);
	ft_strlcpy(key, env, size_key + 1);
	return (key);
}

char	*ft_value(char *str)
{
	char	*value;

	value = NULL;
	value = ft_ajouter_value(str);
	return (value);
}

t_envp	*ft_new_node_env(char *env)
{
	t_envp	*envp;

	envp = NULL;
	envp = (t_envp *)malloc(sizeof(t_envp));
	if (!envp)
		return (NULL);
	envp->envp_str = ft_strdup(env);
	envp->envp_key = ft_key(env);
	envp->envp_value = ft_value(env);
	envp->next = envp;
	envp->prev = envp;
	return (envp);
}

void	ft_ajouter_node(t_envp **envp, t_envp *new)
{
	if (!envp || !new)
		return ;
	if (!*envp)
		*envp = new;
	else
	{
		(*envp)->prev->next = new;
		new->prev = (*envp)->prev;
		(*envp)->prev = new;
		new->next = (*envp);
	}
}

int	ft_env_len(char **env)
{
	int	ret;

	ret = 0;
	while (env[ret])
		ret++;
	return (ret);
}

void	ft_node_list_env(t_envp **envp_list, char **env)
{
	int	i;
	int	last_env;

	last_env = ft_env_len(env) - 1;
	i = 0;
	while (i < last_env)
	{
		ft_ajouter_node(envp_list, ft_new_node_env(env[i]));
		i++;
	}
	g_info.last_env_str = ft_strdup(env[last_env]);
}

void	ft_print_env(t_envp *envp)
{
	t_envp	*tmp;

	if (!envp)
		return ;
	tmp = envp->prev;
	while (envp != tmp)
	{
		if (!(g_info.flag_pwd == 1 && !ft_strcmp(envp->envp_key, "PWD")))
		{
			ft_putstr(envp->envp_str);
			ft_putstr("\n");
		}
		envp = envp->next;
	}
	if (!(g_info.flag_pwd == 1 && !ft_strcmp(envp->envp_key, "PWD")))
	{
		ft_putstr(envp->envp_str);
		ft_putstr("\n");
	}
	ft_putstr(g_info.last_env_str);
	ft_putstr("\n");
}
