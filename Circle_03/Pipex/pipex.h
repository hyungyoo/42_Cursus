#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_info
{
	int		in_file;
	int		out_file;
	int		*pipe_fd;
}				t_info;

char			**ft_split(char *str);

#endif
