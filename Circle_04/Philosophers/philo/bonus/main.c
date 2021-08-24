#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_info	all;
	int		ret;

	if (argc != 5 && argc != 6)
		return (ft_write_error("Wrong amount of arguments"));
	ret = ft_init_all(&all, argv);
	if (ret)
		return (ft_error_manager(ret));
	if (ft_process_loop(&all))
		return (ft_write_error("There was an error creating the threads"));
	return (0);
}
