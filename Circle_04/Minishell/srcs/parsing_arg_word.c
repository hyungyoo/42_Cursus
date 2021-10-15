#include "../includes/minishell.h"

void	argument_word(t_cmd **cmd, char *line, int *index)
{
	int		tmp;
	char	*str;

	tmp = *index;
	while (line[*index] && line[*index] != ' ' && line[*index] != '<' 
		&& line[*index] != '>' && line[*index] != '|' && line[*index] != ';' 
		&& line[*index] != '\"' && line[*index] != '\'' && line[*index] != '\\' 
		&& line[*index] != '$')
		(*index)++;
	if (*index - tmp)
	{
		str = ft_substr(line, tmp, *index - tmp);
		insert_node(cmd, ARG, str);
	}
}
