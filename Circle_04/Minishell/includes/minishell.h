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
// # define WORD 		0
# define SINQ 		1
# define DOUQ 		2
# define DOLR 		3
# define PIPE 		4
# define SEMC 		5
# define LEFT 		6
# define RIGHT 		7
# define DLEFT 		8
# define DRIGHT 	9
# define CMD		10
# define BUILTIN_CMD 11
# define ARG		12
# define FILE		13
# define LIMITER	14

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
	struct s_node	*cmd_start;
} t_cmd;

typedef struct s_envp
{
	char	*envp_str;
	char	*envp_key;
	char	*envp_value;
	struct s_envp	*next;
	struct s_envp	*prev;
}				t_envp;

typedef	struct s_info {
	struct s_envp 	*envp;
	int				exit_code;
} t_info;

/* one global variable */
t_info	g_info;

/* built_in */
void	ft_built_in(t_node **cmd);
void	ft_pwd(t_node **cmd);
void	ft_print_env(t_envp *envp);
void	ft_env(t_node **cmd);
void	ft_export(t_node **cmd);

/* node for env */
void	ft_node_list_env(t_envp **envp_list, char **env);
void	ft_ajouter_node(t_envp **envp, t_envp *new);
t_envp	*ft_new_node_env(char *env);
char	*ft_value(char *key);
char	*ft_key(char *env);
int		ft_size_key(char *str);

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

void	set_detail_type(t_cmd **cmd);
int		is_builtin(char *str);

#endif
