/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:43:09 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/11 14:54:40 by hyungyoo         ###   ########.fr       */
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

typedef struct s_info
{
	char	**env;
	int		count_node;
}				t_info;

typedef struct s_parsing
{
	char	*cmd;
	char	**cmd_option;	// split cmd with ' ' '\t' etc, cmd + option for execve
	char	**arg;			// split arg with ' ' '\t' etc
	char	*next_multi_cmd;
	struct s_parsing *next;
	struct s_parsing *prev;
}				t_parsing;

/* one global variable */
t_info	g_info;

/* parsing.c */
void			parsing(char *str);

/* split_cmd.c*/
char			**ft_split_cmd(char **str);

/* cmd.c */
int				ft_parsing_cmd(char *str);

/* quote.c*/
int				ft_verifier_dquote(char *str);

/* util.c */
int				ft_add(int num);
void			ft_free_double(char **str);
/* exit.c */
void			ft_exit(void);

/* initial.c */
void			ft_initial(char **env);
void			ft_init_node(t_parsing *parsing);

/* signal.c */
void			handler(int signum);
#endif
