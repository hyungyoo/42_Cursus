/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:17:45 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/27 14:17:46 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

void			ft_execve(char *cmd, char **cmd_parsing, char **envp);
char			**ft_split(char *str);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, int	size);
void			ft_print_error(char *str);
int				ft_size_parsing(char **str);
char			**ft_path_parsing(char **envp);
void			ft_free_parsing(char **cmd);
void			ft_pipe_in_child(int *pipe_fd,
					int in_file, char *cmd1, char **envp);
void			ft_pipe_out_parent(int *pipe_fd,
					int out_file, char *cmd2, char **envp);

#endif
