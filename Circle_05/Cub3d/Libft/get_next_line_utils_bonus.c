/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whazami <whazami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:06:47 by whazami           #+#    #+#             */
/*   Updated: 2022/01/26 18:15:38 by ytak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_gnl(const char *s, size_t size)
{
	char	*strr;
	size_t	i;

	strr = (char *)malloc(size + 1);
	if (strr == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i <= size)
	{
		strr[i] = s[i];
		i++;
	}
	while (i <= size)
	{
		strr[i] = '\0';
		i++;
	}
	return (strr);
}

size_t	ft_strlen_gnl(const char *s, char c)
{
	int	cpt;

	cpt = 0;
	while (s[cpt] != c && s[cpt])
		cpt++;
	return (cpt);
}

t_gnl_list	*ft_lstadd_back_gnl(t_gnl_list **alst, int fd)
{
	t_gnl_list	*new;
	t_gnl_list	*p;

	new = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->buf_index = 0;
	new->buffer[0] = '\0';
	new->next = NULL;
	if (!*alst)
	{
		*alst = new;
		return (new);
	}
	p = *alst;
	while (p->next)
		p = p->next;
	p->next = new;
	return (new);
}

void	ft_lstdelone_gnl(t_gnl_list *begin, int fd)
{
	t_gnl_list	*p;
	t_gnl_list	*tmp;

	if (!begin)
		return ;
	p = begin;
	while (p->next && p->next->fd != fd)
		p = p->next;
	if (!p->next)
		return ;
	tmp = p->next;
	p->next = tmp->next;
	free(tmp);
}
