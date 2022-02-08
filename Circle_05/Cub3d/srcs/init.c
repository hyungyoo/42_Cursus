#include "cub3d.h"

void	init_info(t_info *all)
{
	ft_memset(all->env.path, 0, 6);
	all->env.floor = -1;
	all->env.ceiling = -1;
	all->env.width = 0;
	all->env.height = 0;
	all->line = NULL;
	all->player.dir = '\0';
	all->render_buf = NULL;
	all->window_width = 1680;
	all->window_height = 1050;
}
