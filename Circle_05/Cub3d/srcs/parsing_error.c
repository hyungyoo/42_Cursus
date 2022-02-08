#include "cub3d.h"

// parsing error to open the filename
void	fd_open_error(char *file_name, t_info *all)
{
	if (!ft_isformat(file_name, ".cub"))
		ft_strexit("Error: .cub file name needed!💩");
	all->fd = open(file_name, O_RDONLY);
	if (all->fd == -1)
		ft_strexit("Error: No such .cub file existed!🥺 ");
	all->fd_map = open(file_name, O_RDONLY);
	if (all->fd_map == -1)
		ft_strexit("Error: No such .cub file existed!🥺 ");
}

void	xpm_parsing(t_info *all, char *xpm_path, int flag)
{
	int	fd;

	if (!xpm_path || !ft_isformat(xpm_path, ".xpm"))
		ft_strexit("Error: .xpm path is needed!😝");
	fd = open(xpm_path, O_RDONLY);
	if (fd == -1)
		ft_strexit("Error: No such .xpm exists!🤯");
	close (fd);
	all->env.path[flag] = ft_strdup(xpm_path);
}
