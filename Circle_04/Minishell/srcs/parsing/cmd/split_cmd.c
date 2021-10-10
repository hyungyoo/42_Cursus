/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:14:47 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/10 17:34:10 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_strcmp_pivot(char *str)
{
	if (!ft_strcmp(str, "|"))
		return (1);
	else if (!ft_strcmp(str, "<"))
		return (1);
	else if (!ft_strcmp(str, "<<"))
		return (1);
	else if (!ft_strcmp(str, ">"))
		return (1);
	else if (!ft_strcmp(str, ">>"))
		return (1);
	return (0);
}

int	ft_count_pivot(char **str)
{
	int	count_pivot;
	int	i;

	i = 0;
	count_pivot = 0;
	while (str[i])
	{
		if (ft_strcmp_pivot(str[i]))
			count_pivot++;
		i++;
	}
	return (count_pivot);
}

void	ft_free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	tmp = ft_strjoin(s1, " ");
	ret = ft_strjoin(tmp, s2);
	free(tmp);
	free(s2);
	free(s1);
	return (ret);
}

char	**ft_split_cmd(char **str)
{
	char	**ret;
	int		size_split;
	int		i;
	int		ret_index;

	size_split = ft_count_pivot(str) + 1;
	ret = ft_calloc(sizeof(char *), size_split + 1);
	i = 0;
	ret_index = 0;
	while (str[i])
	{
		if (i == 0 && ft_strcmp_pivot(str[i]))
		{
			ret[ret_index++] = strdup(str[i]);
			free(str[i++]);
		}
		else if (str[i])
		{
			ret[ret_index] = strdup(str[i]);
			free(str[i++]);
			while (str[i] && !ft_strcmp_pivot(str[i]))
				ret[ret_index] = ft_strjoin_free(ret[ret_index], str[i++]);
			if (str[i] && ft_strcmp_pivot(str[i]))
				ret[ret_index] = ft_strjoin_free(ret[ret_index], str[i++]);
			ret_index++;
		}
	}
	return (ret);
}

void	ft_print_all(char **ret)
{
	int	i = 0;
	if (!ret)
		return ;
	while (ret[i])
		printf("%s\n", ret[i++]);
}

int	main(void)
{
	char *str = ft_strdup("cat |>infile | grep hello > cat outfile | grep hell");
	char *str2 = ft_strdup("< file_in | cat -e");
	char *str3 = ft_strdup("< |");
	char **ret = ft_split_cmd(ft_split(str, ' '));
	char **ret2 = ft_split_cmd(ft_split(str2, ' '));
	char **ret3 = ft_split_cmd(ft_split(str3, ' '));
	

	printf("\n\n\n");
	printf("%s\n\n", str);
	ft_print_all(ret);	


	printf("\n\n\n");
	printf("%s\n\n", str2);
	ft_print_all(ret2);

	printf("\n\n\n");
	printf("%s\n\n", str3);
	ft_print_all(ret3);

	ft_free_double(ret);
	ft_free_double(ret2);
	ft_free_double(ret3);
	free(str);
	free(str2);
	free(str3);
	printf("\n\n\n");
	return (0);
}

/*
 * 도대체 
 *
 * Process:         a.out [93623]
Path:            /Users/USER//a.out
Load Address:    0x10cfb2000
Identifier:      a.out
Version:         ???
Code Type:       X86-64
Platform:        macOS
Parent Process:  leaks [93622]

Date/Time:       2021-10-10 16:41:49.091 +0200
Launch Time:     2021-10-10 16:41:48.653 +0200
OS Version:      macOS 11.5.2 (20G95)
Report Version:  7
Analysis Tool:   /usr/bin/leaks

Physical footprint:         356K
Physical footprint (peak):  356K
----

leaks Report Version: 4.0
Process 93623: 170 nodes malloced for 12 KB
Process 93623: 2 leaks for 192 total leaked bytes.

    2 (192 bytes) ROOT LEAK: 0x7fba71405990 [96]
       1 (96 bytes) 0x7fba71405a20 [96]

make: *** [all] Error 1

어디인지?

malloc으로 che* * 5를 한다음에
각각을 strduop으로 해도되는지?
*/
