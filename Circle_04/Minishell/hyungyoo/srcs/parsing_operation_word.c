#include "../includes/minishell.h"

int	operation_word(t_cmd **cmd, char *line, int *index)
{
	if (!ft_strncmp(&line[*index], "<", 1))
	{
		if (line[(*index) + 1] == '<')
		{
			insert_node(cmd, DLEFT, ft_strdup("<<"));
			(*index)++;
		}
		else
			insert_node(cmd, LEFT, ft_strdup("<"));
	}
	else if (!ft_strncmp(&line[*index], ">", 1))
	{
		if (line[(*index) + 1] == '>')
		{
			insert_node(cmd, DRIGHT, ft_strdup(">>"));
			(*index)++;
		}
		else
			insert_node(cmd, RIGHT, ft_strdup(">"));
	}
	else if (!ft_strncmp(&line[*index], "|", 1))
	{
		if (line[(*index) + 1] == '|')
		{
			ft_putendl_fd("Syntax error", 1); /* 임시 message */
				return (1);
		}
		else
			insert_node(cmd, PIPE, ft_strdup("|"));
	}
	else if (!ft_strncmp(&line[*index], "$", 1))
		insert_node(cmd, DOLR, ft_strdup("$"));
	return (0);
}
