#include "../includes/minishell.h"

int	parsing_quotes(char *line, int *index, t_cmd **cmd)
{
	int		tmp;
	char	*str;
	char	pair;

	pair = line[(*index)++];
	tmp = *index;
	if (is_quotes_pair(line, index, pair))
		return (EXIT_FAILURE);
	while (line[*index] && line[*index] != pair)
		(*index)++;
	// printf("index : %d\n", *index);
	str = ft_substr(line, tmp, *index - tmp); /* dont forget : free needed */
	// printf("str : %s\n", str);
	if (pair == '\"')
		insert_node(cmd, DOUQ, str);
	else if (pair == '\'')
		insert_node(cmd, SINQ, str);
	// printf("*index at the end of the ft parsing quoute : %d\n", *index);
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
