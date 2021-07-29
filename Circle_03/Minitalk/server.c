#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_signal_handler(int signal)
{
	static int	c;
	static int	count;

	count += 1;
	c = c << 1;
	if (signal == SIGUSR2)
		c += 1;
	if (count == 8)
	{
		ft_putchar(c);
		c = 0;
		count = 0;
	}
}

int		main(void)
{
	char	*pid;
	int		get_pid;

	get_pid = getpid();
	if (!(100 <  get_pid && get_pid < 100000))
		perror("pid out of range");
	pid = ft_itoa(get_pid);
	ft_putstr(pid);
	ft_putchar('\n');
	free(pid);
	signal(SIGUSR1, ft_signal_handler);
	/*
	if (signal_1 == -1)
		perror("SIGSR1 error");
	*/
	signal(SIGUSR2, ft_signal_handler);
	/*
	if (signal_1 == -1)
		perror("SIGSR2 error");
	*/
	while (42)
		pause();
	return (0);
}
