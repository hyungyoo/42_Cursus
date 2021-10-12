/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:43:09 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/13 00:54:28 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <stdbool.h>

# include "../libft/libft.h"

# define PIPE 5
# define LEFT 6
# define DLEFT 7
# define RIGHT 8
# define DRIGHT 9

typedef struct s_info
{
	char	**env;
	int		count_node;
	char	**split_cmd;
}				t_info;

typedef struct s_parsing
{
	char				*cmd;            //ls --> 
	char				*access_cmd;    // path + cmd, null->error_message
	char				**cmd_arg;	// cmd + arg --> 2 array   ls // -al
	int					flag;
	struct s_parsing	*next;
}				t_parsing;

/* one global variable */
t_info	g_info;

/* parsing.c */
void			parsing(char *str);


////////////지울것
void			ft_printf_parsing_cmd(char **cmd);
void			ft_print_all_node(t_parsing *parsing);
void			ft_print_node(t_parsing *a);
int				ft_size_node(t_parsing *a);
////////////////
//
//
/* split_cmd.c*/
char			**ft_split_cmd(char **str);
int				ft_strcmp_pivot(char *str);

/* cmd.c */
int				ft_parsing_cmd(char *str, char ***split_cmd);

/* quote.c*/
int				ft_verifier_dquote(char *str);
int				ft_dquote(char *str);
int				ft_quote(char *str);
int				ft_verifier_quote(char c);

/* util.c */
int				ft_add(int num);
void			ft_free_double(char **str);
/* exit.c */
void			ft_exit(void);

/* initial.c */
void			ft_initial(char **env);
void			ft_init_node(t_parsing **parsing, char **split_cmd);

/* signal.c */
void			handler(int signum);
#endif
