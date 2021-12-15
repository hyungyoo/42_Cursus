/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:43:23 by seyun             #+#    #+#             */
/*   Updated: 2021/12/03 15:12:23 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define OPEN_MAX 32
# define BUFFER_SIZE 1
# define NL 1
# define _EOF 0
# define ERROR -1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char		*ft_strchr(const char *s, int c);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strnstr(const char *big, const char *litt, size_t len);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
void		ft_bzero(void *dest, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t size);
void		*ft_memset(void *dest, int val, size_t size);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t size, size_t count);
char		*ft_itoa(int n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t size);
void		*ft_memchr(const void *ptr, int value, size_t size);
int			ft_memcmp(const void *p1, const void *p2, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t size);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *ptr);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_isformat(char *str, char *format);
void		ft_strexit(char *str);
void		ft_free_double(char **str);
int			ft_longest_node_len(t_list *lst);
int			ft_isset(char c, char *str);
int			get_next_line(int fd, char **line);
int			ft_strcmp(const char *s1, const char *s2);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_only_digit(char *str);
char		*ft_strndup(char *s1, size_t size);
char		*ft_strcpy(char *dst, char *src, size_t n);

#endif
