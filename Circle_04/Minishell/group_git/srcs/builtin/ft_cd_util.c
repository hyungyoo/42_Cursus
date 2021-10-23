/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:26:22 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/23 04:29:37 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strjoin_cd(char *s1, char *s2)
{
	int		new_str_len;
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new_str_len = ft_strlen(s1) + ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = (char *)ft_calloc((new_str_len + 1), sizeof(char));
	if (!(new))
		return (NULL);
	while (s1[i] != '\0')
		new[i++] = (char)s1[j++];
	j = 0;
	while (s2[j] != '\0')
		new[i++] = (char)s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

int	ft_strlen_avant_slash(char *path)

{
	int	len;

	len = ft_strlen(path) - 1;
	if (path[len] == '/')
		len--;
	while (len >= 0)
	{
		if (path[len] == '/')
			return (len);
		len--;
	}
	return (0);
}

void	ft_avant_path(char **path)
{
	int	size_new_path;
	char	*new_path;

	new_path = NULL;
	if (!*path || !path)
		return ;
	size_new_path = ft_strlen_avant_slash(*path);
	if (size_new_path <= 0)
	{
		free(*path);
		*path = ft_strdup("/");
		return ;
	}
	new_path = (char *)malloc(sizeof(char) * size_new_path + 1);
	ft_strlcpy(new_path, *path, size_new_path + 1);
	free(*path);
	*path = new_path;
}

void	ft_ajouter_path(char **path, char *add_path)
{
	if (!path || !*path || !add_path)
		return ;
	printf("%c ! \n", (*path)[ft_strlen(*path) - 1]);
	if (!(!ft_strcmp(*path, "/") || (*path)[ft_strlen(*path) - 1] == '/'))
		*path = ft_strjoin_cd(*path, "/");
	*path = ft_strjoin_cd(*path, add_path);
}

void	ft_cd_exec(char **path, char *new_path)
{
	char	**path_split;
	int		i;

	if (new_path[0] == '/')
	{
		free(*path);
		*path = ft_strdup(new_path);
		return ;
	}
	i = -1;
	path_split = ft_split(new_path, '/');
	while (path_split[++i])
	{
		if (!ft_strcmp(path_split[i], "."))
			continue ;
		else if (!ft_strcmp(path_split[i], ".."))
			ft_avant_path(path);
		else
			ft_ajouter_path(path, path_split[i]);
	}
	free_tab2(path_split);
}
