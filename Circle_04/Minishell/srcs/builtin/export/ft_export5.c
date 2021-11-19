/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:49:16 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/19 18:49:18 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_nbr_words(char *str, char c)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0' && \
			(str[i + 1] == c || str[i + 1] == '\0'))
		{
			i++;
			nbr++;
		}
		if (str[i] == '\0')
			return (nbr);
		i++;
	}
	return (nbr);
}

static int	ft_word_size(char *str, int k, char c)
{
	int	word_size;

	word_size = 0;
	while (str[k] != c && str[k] != '\0')
	{
		word_size++;
		k++;
	}
	return (word_size);
}

static void	free_tab(char **t)
{
	int	idx;

	idx = 0;
	while (t[idx])
	{
		free(t[idx]);
		idx++;
	}
	free(t);
}

static char	**spl_f(char **new_str, char *str, char c, int i)
{
	int	j;
	int	k;

	k = 0;
	while (str[k])
	{
		while (str[k] == c && str[k])
			k++;
		if (str[k])
		{
			j = 0;
			new_str[i] = malloc(sizeof(char) * (ft_word_size(str, k, c) + 1));
			if (!(new_str[i]))
			{
				free_tab(new_str);
				free(new_str);
				return (NULL);
			}
			while (str[k] != c && str[k])
				new_str[i][j++] = str[k++];
			new_str[i++][j] = '\0';
		}
	}
	new_str[i] = 0;
	return (new_str);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	char	*str;

	str = (char *)s;
	if (!(str))
		return (NULL);
	new_str = malloc((ft_nbr_words(str, c) + 1) * sizeof(char *));
	if (!(new_str))
		return (NULL);
	new_str = spl_f(new_str, str, c, 0);
	if (!(new_str))
		return (NULL);
	return (new_str);
}
