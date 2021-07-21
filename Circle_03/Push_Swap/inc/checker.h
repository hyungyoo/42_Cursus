#ifndef	CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

#define  BUFFER_SIZE 1

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strjoin(const char *s1, const char *s2);
int			ft_strchr(const char *s, int c);
char		*ft_substr(const char *str, unsigned int start, size_t len);

/*
 * ft_asc_des.c
 */
int			ft_check_ascending(t_stack *stack, int size);
int			ft_check_descending(t_stack *stack, int size);

/*
 * ft_ajouter_node.c
 */
t_stack		*ft_new_node(char *num);
void		ft_ajouter_node(t_stack **stack, t_stack *node);

/*
 * ft_ajouter_node_split.c
 */
void		ft_ajouter_node_split(t_stack **stack, char *num);

/*
 * ft_atoi.c
 */
int			ft_atoi_size(char *num);

/*
 * ft_free.c
 */
void		ft_stack_free(t_stack *stack);
void		ft_free_split(char **str);

/*
 * ft_print.c
 */
void		ft_putstr(char *str);
void		ft_print_error(void);

/*
 * ft_split.c
 */
int			ft_isspace(char c);
int			count_words(char *str);
char		*malloc_word(char *str);
char		**ft_split(char *str);

/*
 *  ft_verifier.c
 */
int			ft_digit(char c);
int			ft_verifier_argv(char *num);
int			ft_verifier_split(char *num);
int			ft_check_duplicate(t_stack *stack);

/*
 * main.c
 */
void		ft_init_stack(t_stack **stack_a, char **argv);
int			main(int argc, char **argv);

#endif
