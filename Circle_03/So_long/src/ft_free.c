#include "../so_long.h"

void	ft_free(t_info *all)
{
	int	i;

	i = 0;
	while (all->map.map_array[i])
		free(all->map.map_array[i++]);
	free(all->map.map_array);
	close(all->map.fd);
	close(all->map.fd2);
}
