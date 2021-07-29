#include "pipex.h"

void	ft_check_pipex_error(t_info **info)
{
	if ((*info)->fd_input < 0)
		ft_print_error(strerror(errno), 0);
	if ((*info)->fd_output < 0)
		ft_print_error(strerror(errno), 0);
	(*info)->cmd1_parsing = ft_split((*info)->cmd1, ' ');
	ft_cmd_path(info, 1);
	(*info)->cmd2_parsing = ft_split((*info)->cmd2, ' ');
	ft_cmd_path(info, 2);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;

	info = NULL;
	if (argc != 5)
		ft_print_error("to use: '> ./pipex file1 cmd1 cmd2 file2'.", 1);
	info = (t_info *)malloc(sizeof(t_info));
	if (pipe(info->pipe_fd) == -1)
		ft_print_error("Pipe(): pipe error.", 1);
	info->fd_input = open(argv[1], O_RDONLY);
	info->fd_output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	info->envp = envp;
	info->cmd1 = argv[2];
	info->cmd2 = argv[3];
	ft_check_pipex_error(&info);
	ft_pipex(info);
	close(info->fd_input);
	close(info->fd_output);
	if (WIFEXITED(info->fd_status))
		return (WEXITSTATUS(info->fd_status));
	return (0);
}
