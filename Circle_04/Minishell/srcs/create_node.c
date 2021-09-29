#include "../includes/minishell.h"

void	insert_node(t_pars **node, int value)
{
	t_pars	*new;
	t_pars	*tmp;

	new = (t_pars *)malloc(sizeof(t_pars));
	if (!new)
		ft_exit_msg("ERROR");
	tmp = *node;
	new->next = NULL;
	new->prev = NULL;
	new->type = value;
	if (tmp == NULL)
	{
		*node = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}