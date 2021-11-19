/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:59:39 by keulee            #+#    #+#             */
/*   Updated: 2021/11/19 17:01:18 by hyungyoo         ###   ########.fr       */
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

typedef struct s_fd_pipe
{
	int	fd_in;
	int	fd_out;
	int	fd_std_in;
	int	fd_std_out;
	int	fd_std_in_pipe;
	int	fd_std_out_pipe;
	int	fd_heredoc_pipe[2];
	int	pipe_fd[2];
}			t_fd_pipe;

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

/*
 * logo
 */
/* ascii_logo.c */
void			ascii_logo_lol(void);

/*
 * minishell
 */
/* minishell */
void			execute_eof(t_cmd *cmd, char *line);
void			execute_parsing(t_cmd *cmd, char *line);
void			execute_minishell(t_cmd *cmd, char *line);
int				main(int ac, char **av, char **env);

/*
 * parsing
 */
/* parsing.c */
int				parsing_process(char *str, t_cmd **cmd, int *i);
void			insert_nospace_flag(t_cmd **cmd);
char			*remove_quote(char *line);
int				ft_parsing(char *line, t_cmd **cmd);

/* parsing_quote.c*/
int				parsing_quotes(char *str, int *index, t_cmd **cmd);
int				is_quotes_pair(char *str, int *index, char pair);

/* parsing_arg_word.c */
void			argument_word(t_cmd **cmd, char *line, int *index);

/*  parsing_operation_word.c */
void			parsing_left(char *line, t_cmd **cmd, int *index);
void			parsing_right(char *line, t_cmd **cmd, int *index);
int				operation_word(t_cmd **cmd, char *line, int *index);

/* set_detail_type.c */
int				is_builtin(char *str);
int				is_operation_word(t_node *node);
void			first_cmd_type(t_cmd **cmd);
void			set_cmd_next_pipe(t_node *tmp);
void			set_detail_type(t_cmd **cmd);

/* get_type_dir.c */
void			ft_change_type(t_node **node);
void			ft_type_cmd(t_node *node);
void			get_type_dir_file(t_node *node);
void			get_type_dir(t_node *node, t_cmd *cmd);

/*
 * signal
 */
/* signal.c */
void			hanlder_child_pid(int signum);
void			handler(int signum);

/*
 * initial 
 */
/* copy_env.c */
void			copy_env(char **env);
void			ft_initial_g(void);
void			ft_initial(char **env, int ac, char **av);

/*
 * free
 */
/* ft_free_exit.c */
void			ft_free_env(t_envp *envp);
void			ft_exit(int exit_code);
void			ft_exit_minishell(int exit_code, t_cmd **cmd);

/* 
 * list of cmd line
 */
/* list.c */
t_cmd			*init_cmd(void);
void			insert_node(t_cmd **cmd, int type, char *str);
void			free_list(t_cmd **cmd);
int				get_listsize(t_node **node);
void			print_cmdline(t_cmd **cmd);

/*
 * execute
 */
/* execute.c */
void			ft_move_to_last(t_node **node);
void			ft_error_message_left(char *str);
int				ft_left_fd(t_node **node, t_fd *fd);
void			heredoc_parent(t_fd *fd, int status);
void			heredoc_child(t_fd *fd, t_cmd *cmd, t_node **node);
int				ft_dleft_fd(t_node **node, t_fd *fd, t_cmd *cmd);
int				ft_right_fd(t_node **node, t_fd *fd);
int				ft_dright_fd(t_node **node, t_fd *fd);
int				ft_fd_checker(t_node *node, t_fd *fd, t_cmd *cmd);
void			ft_execve_cmd(t_node **node, t_cmd *cmd);
void			ft_set_fd(t_fd *fd);
void			ft_close_fd(t_fd *fd);
void			execute_cmds(t_node **node, t_cmd *cmd);
int				count_pipe(t_node *node);
void			ft_error_message_exec(void);
int				ft_check_pipe_error(t_node *node);
void			ft_exec(t_cmd *cmd);

/* execute_cmd.c */
char			*get_path(char *str);
int				count_arg(t_node *node);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_arg(t_node **node);
char			**get_arg(t_node *node);
int				ft_error_message_path(char *path, char **argv, char **env);
int				ft_error_message_pwd(char *path, char **argv,
					char **env);
int				ft_error_message(char *path, char **argv, char **env);
int				ft_error_message_no_path(char **argv, char **env);
void			ft_execmd_child(t_node *node);
int				ft_check_path_exec(t_node *node);
void			ft_error_message_execmd(t_cmd *cmd_start);
void			ft_execmd(t_node *node, t_cmd *cmd_start);

/* execute_pipe.c */
int				check_cmd(t_node *node);
int				ft_left_fd_pipe(t_node **node, t_fd_pipe *fd, int flag);
void			heredoc_parent_pipe(t_fd_pipe *fd, int status);
void			heredoc_child_pipe(t_fd_pipe *fd, t_cmd *cmd, t_node **node);
void			heredoc(t_cmd *cmd, t_node *node);
int				ft_dleft_fd_pipe(t_node **node, t_fd_pipe *fd,
					t_cmd *cmd, int flag);
int				ft_right_fd_pipe(t_node **node, t_fd_pipe *fd, int flag);
int				ft_dright_fd_pipe(t_node **node, t_fd_pipe *fd, int flag);
int				ft_fd_checker_pipe(t_node *node, t_fd_pipe *fd,
					t_cmd *cmd, int flag);
void			ft_set_fd_pipe(t_fd_pipe *fd);
void			ft_close_fd_pipe(t_fd_pipe *fd);
void			execute_cmds_pipe(t_node **node, t_cmd *cmd, t_fd_pipe *fd);
void			execute_pipe(t_node **node, t_cmd *cmd);
void			ft_exec_pipe(t_node *node, t_cmd *cmd);
int				check_next_pipe_node(t_node **node);
int				check_dleft_next_cmd(t_node *node);
int				check_dleft(t_node *node);
int				check_dleft_file(t_node *node);

/* expansion.c */
void			ft_del_list_one_node(t_cmd *cmd, t_node *node);
void			ft_del_list_last_node(t_cmd *cmd, t_node *node);
void			ft_del_list(t_cmd *cmd, t_node *node);
void			ft_reset_value_exit_code(t_cmd *cmd, t_node **node);
void			ft_reset_value(t_cmd *cmd, t_node **node);
void			malloc_new_str(char **new_str, char c);
void			ft_ajouter_char(char **new_str, char c);
char			*tmp_key_expansion(char *str, int *i, int j);
void			ft_ajouter_dolr(char **new_str, char *str, int *i);
void			ft_ajouter_exit_code(char **new_str, int *i);
void			ft_ajouter_dolr_code(char **new_str, int *i);
void			ft_reset_value_douq(t_cmd *cmd, t_node **node);
void			ft_expension(t_cmd **cmd);
int				check_exit_char(char c);

/*
 * built in
 */
/* ft_node_list_env.c */
int				ft_check_redir_str(char *str);
int				ft_check_redir_type(t_node *node);
char			*ft_getenv(t_envp *envp, char *key);
char			*ft_getenv_echo(t_envp *envp, char *key);
int				ft_size_key(char *str);
char			*ft_key(char *env);
char			*ft_value(char *str);
t_envp			*ft_new_node_env(char *env);
void			ft_ajouter_node(t_envp **envp, t_envp *new);
int				ft_env_len(char **env);
void			ft_node_list_env(t_envp **envp_list, char **env);
void			ft_print_env(t_envp *envp);

/*  ft_built_in.c */
void			ft_built_in_pipe(t_node	**cmd, t_cmd *cmd_start);
void			ft_built_in(t_node	**cmd, t_cmd *cmd_start);

/* ft_pwd.c */
char			*ft_getenv_pwd(void);
void			ft_pwd(t_node **cmd);

/* ft_env.c */
void			ft_update_last_env(char	*path);
void			ft_env(t_node **cmd);

/*  ft_export.c */
int				ft_is_lettre(char c);
char			*ft_ajouter_value(char *str);
void			ft_update_env(t_envp *envp, char *str, char *key);
int				ft_size_node(t_envp *envp);
char			**ft_array_double_env(void);
int				ft_tab_size(char **str);
void			ft_sort_env(char **env_sort);
void			ft_putstr_with_douq(char *str);
void			ft_export_env(void);
void			ft_error_message_export(char *str);
int				ft_check_num(char *str);
int				ft_check_str(char *str);
int				ft_check_all(char **str);
char			*ft_all_arg(t_node **cmd);
void			ft_export_set_node(char **str);
int				ft_check_arg(t_node *node);
void			ft_export(t_node **cmd);

/* ft_unset.c */
int				ft_chercher_key(t_envp *envp, char *arg);
void			ft_free_one_node(t_envp *envp, char *arg);
void			ft_unset_exec(t_node **cmd);
void			ft_unset(t_node **cmd);

/*  ft_exit.c */
void			ft_free_cmd(t_node *cmd);
int				ft_check_num_exit(char *str);
int				ft_check_pipe_before_exit(t_cmd *cmd);
int				ft_set_exit_code(char *str);
void			ft_exit_with_message(t_cmd *cmd_start);
void			ft_error_message_string_arg(t_node *node, t_cmd *cmd);
void			ft_exit_builtin(t_node **cmd, t_cmd *cmd_start);

/*  ft_cd.c */
void			ft_error_message_cd(char *new_path);
int				ft_new_path(char **path, char *new_path);
char			**ft_split_cd(char *new_path);
int				ft_check_error(char **path, char *new_path);
int				ft_exec_chdir(char **path, char *new_path, char *path_tmp,
					char **split_new_path);
int				ft_exec_dir(char **path, char *new_path);
int				ft_get_path_home(char **path);
void			ft_update_path_oldpath(char *path_env, char *old_pwd);
void			ft_exec_home(void);
void			ft_exec_path(char *new_path);
int				ft_num_arg_cd(t_node *cmd);
void			ft_cd(t_node **cmd);

/* ft_cd_util.c */
char			*ft_strjoin_cd(char *s1, char *s2);
int				ft_strlen_avant_slash(char *path);
void			ft_avant_path(char **path);
void			ft_ajouter_path(char **path, char *add_path);
void			ft_cd_exec(char **path, char *new_path);

/* ft_echo.c */
int				ft_check_option(char *str);
void			ft_put_last_env(void);
void			ft_echo_type_dolr(t_node **cmd);
void			ft_echo_type_douq(t_node **cmd);
int				ft_check_sans_espace(char *str);
void			ft_echo_type_douq_sans_espace(char **key, char *str);
int				ft_check_quote(char *str);
char			*ft_find_key(char *str, int start_index, int *last_index);
int				ft_check_last(char *str, int *last_index);
void			ft_print_env_quote(char *str, int *last_index);
void			ft_type_douq_with_quote(char *str);
void			ft_type_douq_sans_espace(t_node **cmd);
int				ft_not_type(t_node *node);
void			ft_print_echo(t_node **cmd);
int				check_pwd(t_node **cmd);
void			ft_echo(t_node **cmd);

#endif
