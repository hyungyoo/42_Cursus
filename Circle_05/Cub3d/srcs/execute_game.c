#include "cub3d.h"

void	execute_game(t_info	*all)
{
	all->win = mlx_new_window(all->mlx,
			all->window_width, all->window_height, TITLE);
	mlx_hook(all->win, X_EVENT_KEY_PRESS, 0, execute_keypress, all);
	mlx_hook(all->win, X_EVENT_KEY_EXIT, 0, exit_key, all);
	mlx_loop_hook(all->mlx, execute_ray, all);
	mlx_loop(all->mlx);
}

int	execute_ray(t_info	*all)
{
	set_floor_ceiling_color(all);
	set_ray(all);
	render_buffer(all);
	return (0);
}

/*
 * ray값을 만들어서 버퍼에 저장
 * */
void	set_floor_ceiling_color(t_info	*all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->window_height)
	{
		x = 0;
		while (x < all->window_width)
		{
			if (y > all->window_height / 2)
				all->render_buf[y][x] = all->env.floor;
			else
				all->render_buf[y][x] = all->env.ceiling;
			x++;
		}
		y++;
	}
}

void	set_ray(t_info *all)
{
	int	pixel;

	pixel = 0;
	while (pixel < all->window_width)
	{
		init_ray(all, &all->player, &all->ray, pixel);
		set_side_dist(&all->player, &all->ray);
		execute_dda(all, &all->ray);
		set_prep_wall_dist(&all->player, &all->ray);
		set_wall_height(all, &all->ray);
		strip_wall_texture(&all->player, &all->ray);
		strip_wall_color(all, &all->ray, pixel);
		pixel++;
	}
}

void	render_buffer(t_info	*all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->window_height)
	{
		x = 0;
		while (x < all->window_width)
		{
			all->img.data[all->window_width * y + x] = all->render_buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img.ptr, 0, 0);
}
