/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:34:10 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 04:22:13 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

void	*ft_memset(void *dest, int a, size_t len);
void	ft_bzero(void *dest, size_t n);
void	*ft_memcpy(void *restrict dest, const void *src, size_t size);
void	*ft_memccpy(void *restrict dest, const void *restrict src, int c,
			size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t size);
void	*ft_memchr(const void *s1, int c, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src,
			size_t size);
size_t	ft_strlcat(char *restrict dst, const char *restrict src,
			size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int i);
int		ft_isalnum(int a);
int		ft_isascii(int c);
int		ft_isprint(int a);
int		ft_tolower(int i);
int		ft_toupper(int i);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void(*del)(void *));
void	ft_lstclear(t_list **lst, void(*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
