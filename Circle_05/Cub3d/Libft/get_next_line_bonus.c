/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:10:35 by ytak              #+#    #+#             */
/*   Updated: 2022/01/26 18:15:23 by ytak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fill_buf_with_read(char *buffer, int fd, char **line, t_gnl_list *b)
{
	ssize_t		read_ret;

	read_ret = read(fd, buffer, BUFFER_SIZE);
	if (read_ret <= 0)
	{
		if (!*line)
		{
			*line = ft_strdup_gnl("", 1);
			if (!*line)
				return (-1);
		}
		if (read_ret == -1)
		{
			free(*line);
			*line = NULL;
		}
		ft_lstdelone_gnl(b, fd);
		return (read_ret);
	}
	buffer[read_ret] = '\0';
	return (1);
}

static int	manage_line(char **line, char *buffer)
{
	int		len_line;
	char	*tmp;

	if (ft_strlen_gnl(buffer, '\n') < ft_strlen_gnl(buffer, '\0'))
		len_line = ft_strlen_gnl(buffer, '\n') + 1;
	else
		len_line = ft_strlen_gnl(buffer, '\0');
	if (!*line)
	{
		*line = ft_strdup_gnl("", 1);
		if (!*line)
			return (-1);
	}
	tmp = ft_strdup_gnl(*line, ft_strlen_gnl(*line, '\0'));
	if (!tmp)
		return (-1);
	free(*line);
	*line = ft_strdup_gnl(tmp, ft_strlen_gnl(tmp, '\0') + len_line);
	if (!*line)
		return (-1);
	free(tmp);
	return (1);
}

static int	fill_line_with_buf(char **line, char *buf, int *line_i, int *buf_i)
{
	while (buf[*buf_i])
	{
		if (buf[*buf_i] == '\n')
		{
			(*line)[*line_i] = '\0';
			(*buf_i)++;
			return (1);
		}
		(*line)[*line_i] = buf[*buf_i];
		(*line_i)++;
		(*buf_i)++;
	}
	return (0);
}

static t_gnl_list	*get_lst(t_gnl_list *begin, int fd, const char **line)
{
	t_gnl_list	*p;

	if (BUFFER_SIZE <= 0 || !line)
		return (NULL);
	p = begin;
	while (p)
	{
		if (p->fd == fd)
			return (p);
		p = p->next;
	}
	return (ft_lstadd_back_gnl(&begin, fd));
}

int	get_next_line(int fd, char **line)
{
	static t_gnl_list	lst[1];
	t_gnl_list			*cur;
	int					i;
	int					ret;

	cur = get_lst(lst, fd, (const char **)line);
	if (cur == NULL)
		return (-1);
	*line = NULL;
	i = 0;
	while (1)
	{
		if (!cur->buffer[cur->buf_index])
		{
			ret = fill_buf_with_read(cur->buffer, fd, line, lst);
			if (ret != 1)
				return (ret);
			cur->buf_index = 0;
		}
		if (manage_line(line, cur->buffer + cur->buf_index) == -1)
			return (-1);
		if (fill_line_with_buf(line, cur->buffer, &i, &cur->buf_index))
			return (1);
	}
}
