/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:26:25 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/01 16:46:13 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_option(char *str)
{
	int	i;

	i = 0;
	if (str[i++] != '-')
		return (0);
	while (str[i])
		if (str[i++] != 'n')
			return (0);
	return (1);
}

void	ft_put_last_env(void)
{
	ft_putstr((g_info.last_env_str + 2));
	ft_putstr("\n");
}

void	ft_echo_type_dolr(t_node **cmd)
{
	if ((*cmd)->flag_nospace == 0)
	{
		ft_putstr("$");
		return ;
	}
	else if ((*cmd)->next && (*cmd)->flag_nospace == 1)
		(*cmd) = (*cmd)->next;
	if ((*cmd)->type == 12)
	{
		if (!ft_strcmp((*cmd)->str, "?"))
			ft_putnbr_fd(g_info.exit_code, 1);
		else if (!ft_strcmp((*cmd)->str, "_"))
			ft_put_last_env();
		else
		{
			if (ft_getenv_echo(g_info.envp, (*cmd)->str))
				ft_putstr(ft_getenv(g_info.envp, (*cmd)->str));
		}
	}
}

void	ft_echo_type_2(t_node **cmd)
{
	if (((*cmd)->str)[0] == '$')
	{
		if (!ft_strcmp((*cmd)->str + 1, "?"))
			ft_putnbr_fd(g_info.exit_code, 1);
		else if (!ft_strcmp((*cmd)->str + 1, "_"))
			ft_put_last_env();
		else
		{
			if (ft_getenv_echo(g_info.envp, (*cmd)->str + 1))
				ft_putstr(ft_getenv(g_info.envp, (*cmd)->str + 1));
		}
	}
	else
		ft_putstr((*cmd)->str);
}

int	ft_check_sans_espace(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			count++;
		i++;
	}
	return (count);
}

void	ft_echo_type_2_sans_espace(char **key, char *str)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (i == 0 && str[0] != '$')
			ft_putstr(key[i]);
		else if (!ft_strcmp(key[i], "?"))
			ft_putnbr_fd(g_info.exit_code, 1);
		else
		{
			if (ft_getenv_echo(g_info.envp, key[i]))
				ft_putstr(ft_getenv_echo(g_info.envp, key[i]));
		}
		i++;
	}
}

int	ft_check_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 39)
			return (1);
		i++;
	}
	return (0);
}

/*
 *	trouver last_index point and malloc and return env;
 */
char	*ft_find_key(char *str, int start_index, int *last_index)
{
	char	*ret;
	int		size_str;
	int		i;

	i = 0;
	size_str = *last_index - start_index + 1;
	ret = (char *)malloc(sizeof(char) * size_str + 1);
	if (!ret)
		return (NULL);
	while (i < size_str)
	{
		ret[i] = str[start_index];
		i++;
		start_index++;
	}
	ret[i] = '\0';
	return (ret);
}

int	ft_check_last(char *str, int *last_index)
{
	if (str[*last_index] == 39 || str[(*last_index)] == '$'
		|| str[*last_index] == ' ' || !str[(*last_index)])
	{
		(*last_index)--;
		return (1);
	}
	return (0);
}

void	ft_print_env_quote(char *str, int *last_index)
{
	int		start_index;
	char	*find_key;

	start_index = ++(*last_index);
	while (42)
	{
		if (ft_check_last(str, last_index))
		{
			find_key = ft_find_key(str, start_index, last_index);
			if (!ft_getenv_echo(g_info.envp, find_key))
			{
				free(find_key);
				return ;
			}
			ft_putstr(ft_getenv_echo(g_info.envp, find_key));
			free(find_key);
			return ;
		}
		(*last_index)++;
	}
}

void	ft_type2_with_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			ft_print_env_quote(str, &i);
		else
			ft_putchar(str[i]);
		i++;
	}
}

void	ft_type2_sans_espace(t_node **cmd)
{
	char	**split_str;

	split_str = NULL;
	if (ft_check_quote((*cmd)->str))
		ft_type2_with_quote((*cmd)->str);
	else
	{
		split_str = ft_split((*cmd)->str, '$');
		ft_echo_type_2_sans_espace(split_str, (*cmd)->str);
		free_tab2(split_str);
		split_str = NULL;
	}
}

void	ft_print_echo(t_node **cmd)
{
	while (*cmd && ((*cmd)->type != PIPE))
	{
		//printf("\n exit node == %s\n", (*cmd)->str);
		if (!ft_redir_passe_node(cmd))
			return ;
		else if ((*cmd)->type == DOLR)
			ft_echo_type_dolr(cmd);
		else if ((*cmd)->type == DOUQ)
		{
			if (ft_check_sans_espace((*cmd)->str) >= 1)
				ft_type2_sans_espace(cmd);
			else
				ft_echo_type_2(cmd);
		}
		else
			ft_putstr((*cmd)->str);
		if ((*cmd)->next)
			ft_putstr(" ");
		if ((*cmd)->flag_nospace == 1)
			ft_putstr("\b");
		if ((*cmd)->next)
			(*cmd) = (*cmd)->next;
		else
			return ;
	}
}

void	ft_echo(t_node **cmd)
{
	int	flag_option;

	flag_option = 0;
	if (!cmd || !*cmd)
		return ;
	if (!((*cmd)->next))
		return ;
	(*cmd) = (*cmd)->next;
	if (ft_check_option((*cmd)->str))
	{
		flag_option = 1;
		if ((*cmd)->next)
			(*cmd) = (*cmd)->next;
	}
	ft_print_echo(cmd);
	if (!flag_option)
		ft_putstr("\n");
	g_info.exit_code = 0;
}
