#include "../includes/minishell.h"

void	argument_word(t_cmd **cmd, char *line, int *index)
{
	int		tmp;
	char	*str;

	tmp = *index;
	if (ft_is_letter(line[*index]))
	{
		while (line[*index] && ft_is_letter(line[*index]))
			(*index)++;
	}
	else
	{
		while (line[*index] && (line[*index] != ' '))
		(*index)++;
	}
	if (*index - tmp)
	{
		str = ft_substr(line, tmp, *index - tmp);
		insert_node(cmd, WORD, str);
	}
}
