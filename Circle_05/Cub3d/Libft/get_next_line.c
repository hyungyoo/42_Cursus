/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:33:56 by seyun             #+#    #+#             */
/*   Updated: 2021/12/02 11:54:23 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_line(char **line, char **note, char *nl_here)
{
	char	*tmp;

	if (nl_here != NULL)
	{
		*line = ft_strndup(*note, nl_here - *note);
		tmp = ft_strndup(nl_here + 1, ft_strlen(nl_here + 1));
		free(*note);
		*note = tmp;
		return (NL);
	}
	if (*note != NULL)
	{
		*line = *note;
		*note = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (_EOF);
}

int			get_next_line(int fd, char **line)
{
	static char	*note[OPEN_MAX];
	static char	buff[BUFFER_SIZE + 1];
	int			byte;
	char		*tmp;
	char		*nl_here;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (ERROR);
	while ((nl_here = ft_strchr(note[fd], '\n')) == 0
			&& (byte = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[byte] = 0;
		tmp = note[fd] == NULL ? ft_strndup(buff, byte) :
			ft_strjoin(note[fd], buff);
		if (note[fd] != 0)
			free(note[fd]);
		note[fd] = tmp;
	}
	if (byte < 0)
		return (ERROR);
	return (handle_line(line, &note[fd], nl_here));
}
