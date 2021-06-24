#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_element;
	t_list	*new_list;

	new_list = NULL;
	if ((*f) == NULL || (*del) == NULL)
		return (NULL);
	while (lst != NULL)
	{
		(new_element = ft_lstnew((*f)(lst->content)));
		if (!(new_element))
		{
			if (new_element != NULL)
				ft_lstclear(&new_list, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}
