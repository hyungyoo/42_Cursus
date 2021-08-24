#include "philo_bonus.h"

int		main(int argc, char **argv)
{
	t_rules	rules;
	int		ret;

	if (argc != 5 && argc != 6)
		return (ft_write_error("Wrong amount of arguments"));
	ret = ft_init_all(&rules, argv);
	if (ret)
		return (ft_error_manager(ret));
	if (ft_launcher(&rules))
		return (ft_write_error("There was an error creating the threads"));
	return (0);
}
