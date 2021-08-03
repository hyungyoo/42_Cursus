#ifndef SO_LONG_H
# define SO_LONG_H

#define BUFFER_SIZE 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "mlx/mlx.h"

/*
* get_next_line.c
*/
int			ft_line(char *str, char **line, int ret);
char		*ft_rest(char *str);
char		*ft_read_line(char *str, int fd, int *ret);
int			get_next_line(int fd, char **line);

/*
* get_next_line_utils.c
*/
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

/*
* ft_print_error.c
*/
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_print_error(char *str);
int			ft_file_name(char *file_name, char *cmp);

#endif
