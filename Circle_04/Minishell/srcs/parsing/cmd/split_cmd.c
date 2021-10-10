/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:14:47 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/10 16:45:53 by hyungyoo         ###   ########.fr       */
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

char	**ft_malloc_split(int	size_split)
{
	char	**ret;
	
	ret = (char **)malloc(sizeof(char*) * (size_split) + 1);
	if (!ret)
		return (NULL);
	ret[size_split] = NULL;
	return (ret);
}

void	ft_free_double(char **str)
{
	int	i = 0;
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

	tmp= ft_strjoin(s1, " ");
	ret = ft_strjoin(tmp, s2);
	free(tmp);
	free(s2);
	free(s1);
	return (ret);
}

char	**ft_split_cmd(char *str_for_split)
{
	char	**ret;
	char	**str;
	int		size_split;
	int		i;
	int		ret_index;

	str = ft_split(str_for_split, ' ');
	size_split = ft_count_pivot(str) + 1;
	ret = ft_malloc_split(size_split);
	i = 0;
	ret_index = 0;
	while (str[i])
	{
		if (i == 0 && ft_strcmp_pivot(str[0]))
		{
			ret[ret_index++] = strdup(str[0]);
			free(str[0]);
			i++;
		}
		else
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
	char str[100] = "cat |>infile | grep hello > cat outfile | grep hell";
	char str2[100] = "< cat |>infile | grep hello > cat outfile < heool >";
	char **ret = ft_split_cmd(str);
	char **ret2 = ft_split_cmd(str2);
	
	
	printf("%s\n\n", str);
	
	printf("%s\n\n", str2);
	
	printf("\n\n\n");
	printf("ret \n");
	ft_print_all(ret);	
	printf("\n\n\n");
	printf("ret2 \n");
	ft_print_all(ret2);

	ft_free_double(ret);
	ft_free_double(ret2);
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
