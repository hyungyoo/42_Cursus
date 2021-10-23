#include "../includes/minishell.h"

int	parsing_quotes(char *line, int *index, t_cmd **cmd)
{
	int		tmp;
<<<<<<< HEAD
	char	*str;
	char	pair;
=======
	// int		tmp2;
	char	*str;
	// char	*str2;
	// char	*str3;
	char	pair;
	// char	pair2;
>>>>>>> a4dca87f35201104d5264d31de6b48a9cfac1900

	pair = line[(*index)++];
	tmp = *index;
	if (is_quotes_pair(line, index, pair))
		return (EXIT_FAILURE);
	while (line[*index] && line[*index] != pair)
		(*index)++;
	str = ft_substr(line, tmp, *index - tmp);
<<<<<<< HEAD
=======
	// printf("index1 : %d\n", *index);
	// if (line[*index + 1] == '\"' || line[*index + 1] == '\'')
	// 	pair2 = line[*index + 1];
	// if (line[*index + 1] && line[*index + 1] == pair2)
	// {
	// 	// printf("here\n");
	// 	*index += 2;
	// 	tmp2 = *index;
	// 	// printf("index2 : %d\n", *index);
	// 	while (line[*index] && line[*index] != pair2)
	// 		(*index)++;
	// 	str2 = ft_substr(line, tmp2, *index - tmp2);
	// 	// printf("str2 : %s\n", str2);
	// 	str3 = ft_strjoin(str, str2);		
	// 	if (pair == '\"')
	// 		insert_node(cmd, DOUQ, str3);
	// 	else if (pair == '\'')
	// 		insert_node(cmd, SINQ, str3);
	// 	// free(str);
	// 	// free(str2);
	// }
	// printf("index3 : %d\n", *index);
	// else
	// {
>>>>>>> a4dca87f35201104d5264d31de6b48a9cfac1900
	if (*index - tmp)
	{
		if (pair == '\"')
			insert_node(cmd, DOUQ, str);
		else if (pair == '\'')
			insert_node(cmd, SINQ, str);
	}
	return (EXIT_SUCCESS);
}

int	is_quotes_pair(char *line, int *index, char pair)
{
	int tmp;

	tmp = *index;
	while (line[tmp])
	{
		if (line[tmp] == pair)
			return (0);
		tmp++;
	}
	return (1);
}
