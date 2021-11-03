#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

void	ft_putchar(const char c);
void	ft_putstr(const char *str);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_uppercase(char c);
int		ft_space(int i);
int		ft_digit(char c);
char	**ft_split(char const *s, char c);
int		ft_strstr_cub(char *str, char *cub);
int		ft_only_digit(char *str);
int		ft_atoi(const char *str);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlcpy(char *restrict dest, const char *restrict src, size_t size);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_strcmp(char *s1, char *s2);
void	free_tab2(char **str);
int		ft_is_letter(char c);
void	ft_putnbr_fd(int n, int fd);
int		ft_is_digit(char c);
int		get_next_line(int fd, char **line);

#endif
