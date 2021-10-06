/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:43:09 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/06 16:49:12 by hyungyoo         ###   ########.fr       */
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
}				t_info;

typedef struct s_parsing
{
	char	*cmd;
	char	**cmd_option;
	char	**arg;
	struct s_parsing *prev;
	struct s_parsing *next;
}				t_parsing;

/* one global variable */
t_info	g_info;

/* parsing.c */
void			parsing(char *str);

/* quote.c*/
int				ft_verifier_dquote(char *str);

/* util.c */
int				ft_add(int num);

/* exit.c */
void			ft_exit(void);

/* initial.c */
void			ft_initial(char **env);

/* signal.c */
void			handler(int signum);
#endif
