#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

# include "../libft/libft.h"

/*
** TYPE in s_pars
*/
# define WORD 1
# define SINQ 2
# define DOUQ 3
# define DOLR 4
# define PIPE 5
# define SEMC 6
# define LEFT 7
# define RIGHT 8
# define DLEFT 9
# define DRIGHT 10

# define TRUE 1
# define FALSE 0

/* cmd line node */
typedef struct s_node {
	int				type;
	char 			*str;
	struct s_node	*next;
} t_node;

/* cmd struct for counting size and stocking node */
typedef struct s_cmd {
	int				size;
	struct s_node	*cmd_node;
} t_cmd;

typedef	struct s_info {
	char **env;
} t_info;

/* one global variable */
t_info	g_info;

void	ascii_logo_lol(void);

void	handler(int signum);

void	ft_exit(int exit_code);

void    copy_env(char **env);
void	ft_initial_g(void);
void	ft_initial(char **env, int ac, char **av);

int		ft_parsing(char *line, t_cmd **cmd);
int		is_quotes_pair(char *line, int *index, char pair);
int		parsing_quotes(char *line, int *index, t_cmd **cmd);

t_cmd	*init_cmd(void);
void	insert_node(t_cmd **cmd, int type, char *str);
int		get_listsize(t_node **node);
void	print_cmdline(t_cmd **cmd); /* tmp */
void	free_list(t_cmd **cmd);

int		operation_word(t_cmd **cmd, char *line, int *index);
void	argument_word(t_cmd **cmd, char *line, int *index);
int		parsing_quotes(char *line, int *index, t_cmd **cmd);
int		is_quotes_pair(char *line, int *index, char pair);


#endif