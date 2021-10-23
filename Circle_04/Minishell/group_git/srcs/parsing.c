#include "../includes/minishell.h"


void	insert_nospace_flag(t_cmd **cmd)
{
	t_node *node;

	if (!*cmd)
		return ;
	node = (*cmd)->cmd_start;
	while (node->next != NULL)
		node = node->next;
	node->flag_nospace = 1;
}

int ft_parsing(char *line, t_cmd **cmd)
{
	int i;

	i = -1;
	while (line[++i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\"' || line[i] == '\'')
		{
			if (parsing_quotes(line, &i, cmd))
			{
				ft_putendl_fd("Parsing Error", 1); /* 임시 message */
				return (1);
			}
		}
		else if (line[i] == ';' || line[i] == '\\')
		{
			ft_putendl_fd("Parsing error", 1); /* 임시 message */
				return (1);
		}
		else if (line[i] == '<' || line[i] == '>' || line[i] == '|' || line[i] == '$')
		{
			if (operation_word(cmd, line, &i))
			{
				ft_putendl_fd("Parsing error", 1); /* 임시 message */
				return (1);
			}
		}
		else
		{
			/* parse the others*/
			argument_word(cmd, line, &i);
			i--;
		}
		if (line[i + 1] != ' ' && line[i + 1] != '\0') //give a flag if there isn't space after argument.
			insert_nospace_flag(cmd);
	}
	return (0);
}
