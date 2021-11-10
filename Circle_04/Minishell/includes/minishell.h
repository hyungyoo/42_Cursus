/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:59:39 by keulee            #+#    #+#             */
/*   Updated: 2021/11/10 20:32:43 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <sys/types.h>
# include <sys/wait.h>

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
// # define BLANK		15

# define TRUE 1
# define FALSE 0

/* cmd line node */
typedef struct s_node
{
	int				type;
	char			*str;
	int				flag_nospace;
	int				fd[2];
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

/* cmd struct for counting size and stocking node */
typedef struct s_cmd
{
	int				size;
	struct s_node	*cmd_start;
}				t_cmd;

typedef struct s_envp
{
	char			*envp_str;
	char			*envp_key;
	char			*envp_value;
	struct s_envp	*next;
	struct s_envp	*prev;
}				t_envp;

typedef struct s_info
{
	struct s_envp	*envp;
	pid_t			pid_child;
	int				exit_code;
	int				flag_pwd;
	char			*last_env_str;
	int				pipe_flag;
}				t_info;

typedef struct s_fd
{
	int	fd_in;
	int	fd_out;
	int	fd_std_in;
	int	fd_std_out;
	int	fd_heredoc_pipe[2];
}				t_fd;

/* one global variable */
t_info	g_info;

void	ascii_logo_lol(void);

void	handler(int signum);

void	ft_exit_minishell(int exit_code, t_cmd **cmd);
void	ft_exit(int exit_code);
void	get_type_dir(t_node *node);

void	copy_env(char **env);
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
void	insert_nospace_flag(t_cmd **cmd);

int		operation_word(t_cmd **cmd, char *line, int *index);
void	argument_word(t_cmd **cmd, char *line, int *index);
int		parsing_quotes(char *line, int *index, t_cmd **cmd);
int		is_quotes_pair(char *line, int *index, char pair);
int		is_operation_word(t_node *node);
void	parsing_the_rest(t_cmd **cmd, t_node *node);

void	set_detail_type(t_cmd **cmd);
int		is_builtin(char *str);

void	ft_exec(t_cmd *cmd);

void	ft_execmd(t_node *node, t_cmd *cmd_start);
char	**get_arg(t_node *node);
char	*get_path(char *str);
char	*ft_strjoin_free(char *s1, char *s2);

/* built_in */
void	ft_built_in(t_node **cmd, t_cmd *cmd_start);
void	ft_built_in_pipe(t_node **cmd, t_cmd *cmd_start);
void	ft_pwd(t_node **cmd);
void	ft_print_env(t_envp *envp);
void	ft_env(t_node **cmd);
void	ft_export(t_node **cmd);
void	ft_unset(t_node **cmd);
void	ft_echo(t_node **cmd);
void	ft_cd(t_node **cmd);
void	ft_exit_builtin(t_node **cmd, t_cmd *cmd_start);
int		ft_not_type(t_node *node);

/* built_in cd */
char	*ft_strjoin_cd(char *s1, char *s2);
int		ft_strlen_avant_slash(char *path);
void	ft_avant_path(char **path);
void	ft_ajouter_path(char **path, char *add_path);
void	ft_cd_exec(char **path, char *new_path);

/* node for env */
void	ft_node_list_env(t_envp **envp_list, char **env);
void	ft_ajouter_node(t_envp **envp, t_envp *new);
t_envp	*ft_new_node_env(char *env);
char	*ft_value(char *key);
char	*ft_key(char *env);
int		ft_size_key(char *str);
int		ft_check_egal(char *str);
char	*ft_ajouter_value(char *str);
char	*ft_getenv(t_envp *envp, char *key);
char	*ft_getenv_echo(t_envp *envp, char *key);
void	ft_free_env(t_envp *envp);
void	ft_update_env(t_envp *envp, char *str, char *key);
char	**ft_array_double_env(void);
void	ft_update_last_env(char *path);
int		ft_check_redir_str(char *str);
int		ft_check_redir_type(t_node *node);
int		ft_redir_passe_node(t_node **node);
char	*ft_strjoin_free(char *s1, char *s2);

/* expension */

void	ft_expension(t_cmd **cmd);

#endif
