#include "pipex.h"

/*
 * print error + exit()
 */
void	ft_print_error(char *str)
{
	while (*str)
		write(2, str++, 1);
	exit(0);
}

void	ft_free_parsing(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

/*
 * argc 가 5개 미만일떄, 에러출력
 * pipe_fd로 반환받을 스트림 디스크립터 말록
 * in_file 과 out_file의 fd 받기
 */
void	ft_init(t_info *info, int argc, char **argv)
{
	if (argc < 5)
		ft_print_error("to use : ./pipex file1 cmd1 cmd2 fil2\n");
	info->pipe_fd = (int *)malloc(sizeof(int) * 2);
	if (!(info->pipe_fd))
		ft_print_error("error malloc\n");
	if (pipe(info->pipe_fd) == -1)
		ft_print_error("failed to open pipe\n");
	info->in_file = open(argv[1], O_RDONLY);
	if ((info->in_file) == -1)
		ft_print_error("failed to open the input file\n");
	info->out_file = open(argv[4], O_WRONLY);
	if ((info->out_file) == -1)
		ft_print_error("failed to open the output file\n");
}

int	ft_strncmp(char *s1, char *s2, int	size)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < size)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	**ft_path_parsing(char **envp)
{
	int		i;
	char	**path_parsing;
	
	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "PATH=", 5)))
			break;
		i++;
	}
	path_parsing = ft_split(&envp[i][5]);
	return (path_parsing);
}

int	ft_size_parsing(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_size;
	int		s2_size;
	char	*ret;
	int		i;

	i = 0;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_size + s2_size) + 1);
	if (!ret)
		return (NULL);
	while (*s1)
	{
		ret[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		ret[i++] = *s2;
		s2++;
	}
	ret[i] = '\0';
	return (ret);
}
/*
 * ft_execuve -> path + cmd + envp
 * 1. 인자로 들어온 envp를 돌아보며,  PATH가 있는지확인
 * 2. 찾았다면, 그 PATH= 까지는 날려버리고, ':'를 기준으로 parsing
 *
 * 1 과 2는
 * char		**ft_path 함수로, parsing한 PATH를 반환
 *
 * 3. access 함수로, 실제로 가능한 실행파일 경로인지를 확인 후
 * 4. execve 함수 실행
 * 없다면 command not found!
 */
void	ft_execve(char *cmd, char **cmd_parsing, char **envp)
{
	char	**path_parsing;
	int		size_path_parsing;
	int		i;
	char	*path_br;
	char	*path_br_cmd;

	i = 0;
	path_parsing = ft_path_parsing(envp);
	size_path_parsing = ft_size_parsing(path_parsing);
	while (i < size_path_parsing)
	{
		path_br = ft_strjoin(path_parsing[i], "/");
		path_br_cmd = ft_strjoin(path_br, cmd);
		
		/*
		 * test
		 */
		printf("%s\n", path_br_cmd);
		int	j = 0;
		while (cmd_parsing[j])
			printf("parsing cmd : %s\n", cmd_parsing[j++]);
		/*
		 * test
		 */
		if (execve(path_br_cmd, cmd_parsing, envp) != -1)
		{
			/*
			 * test								여기 들어오지를 못하는것같음!!!!!!!!!!!!!!!!!!!!!!!!
			 *									access함수로 바꿔야하나 
			 */
			printf("i am in execve\n");
			/*
			 * test
			 */
			free(path_br);
			free(path_br_cmd);
			break ;
		}
		free(path_br);
		free(path_br_cmd);
		i++;
	}
	free(path_parsing);
	if (i == size_path_parsing)
		ft_print_error("No sush command found\n");
}

void	ft_pipe_out_parent(t_info *info, char *cmd2, char **envp)
{
	char	**cmd_parsing;
	/*
	 * test
	 */
	printf("out parent ?\n");
	/*
	 * test
	 */
	close(info->pipe_fd[1]);
	if (dup2(info->pipe_fd[0], 0) == -1)
		ft_print_error("failed to connect fd of pipe and STDIN parent process\n");
	if (dup2(info->out_file, 1) == -1)
		ft_print_error("failed to connect fd of out_file and STDOUT parent process\n");
	cmd_parsing = ft_split(cmd2);
	if (cmd_parsing[0][0] == '/')
	{
		if (execve(cmd_parsing[0], cmd_parsing, envp) == -1)
			ft_print_error("commande nor found\n");
	}
	else
		ft_execve(cmd_parsing[0], cmd_parsing, envp);
	ft_free_parsing(cmd_parsing);
	close(info->pipe_fd[0]);
	close(info->out_file);
}

/*
 * pipe_fd[1] 을쓴다, 출력이기때문에!
 * 자식 프로세스가 표준출력으로 보내는 모든 데이터가 파이프에 쓰여진다.
 */
void	ft_pipe_in_child(t_info *info, char *cmd1, char **envp)
{
	char	**cmd_parsing;

	/*
	 * test
	 */
	printf("in child  ?\n");
	/*
	 * test
	 */
	close(info->pipe_fd[0]);
	if (dup2(info->in_file, 0) == -1)
		ft_print_error("failed to connect fd of in_file and STDIN child process\n");
	if (dup2(info->pipe_fd[1], 1) == -1)
		ft_print_error("failed to connect fd of pipe and STDOUT child process\n");
	cmd_parsing = ft_split(cmd1);
	if (cmd_parsing[0][0] == '/')
	{
		if (execve(cmd_parsing[0], cmd_parsing, envp) == -1)
			ft_print_error("commande not found\n");
	}		
	else
		ft_execve(cmd_parsing[0], cmd_parsing, envp);
	ft_free_parsing(cmd_parsing);
	close(info->pipe_fd[1]);
	close(info->in_file);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	pid_t	pid;
	int		status;

	pid = fork();
	ft_init(&info, argc, argv);
	if (pid > 0)
	{
		/*
		 * test
		 */
		printf("pid > 0 parent \n");
		/*
		 * test
		 */
		wait(&status);
		ft_pipe_out_parent(&info, argv[3], envp);
	}
	else if (pid  == 0)
	{
		/*
		 * test
		 */
		printf("pid == 0 child\n");
		/*
		 * test
		 */
		ft_pipe_in_child(&info, argv[2], envp);
	}
	else
		ft_print_error("failed to fork the process\n");
	free(info.pipe_fd);
	return (0);
}
