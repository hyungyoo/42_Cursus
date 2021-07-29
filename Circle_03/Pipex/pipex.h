#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

typedef struct s_info
{
	int		fd_input;
	int		fd_output;
	char	*cmd1;
	char	**cmd1_parsing;
	char	*cmd2;
	char	**cmd2_parsing;
	char	**envp;
	int		pipe_fd[2];
	int		fd_status;
}				t_info;

int		ft_strlen(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_pipex(t_info *info);
void	ft_execute_child(t_info *info);
void	ft_execute_parent(t_info *info);
void	ft_check_pipex_error(t_info **info);
void	ft_cmd_path(t_info **info, int cmd_n);
char	*ft_get_path(char **envp);
int		ft_verifier_paths(char *path, char **cmd, char *path_parsing);
void	ft_print_error(char *str, int err);

#endif
