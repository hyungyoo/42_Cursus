#ifndef	CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

#define  BUFFER_SIZE 1

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strjoin(const char *s1, const char *s2);
int			ft_strchr(const char *s, int c);
char		*ft_substr(const char *str, unsigned int start, size_t len);

#endif
