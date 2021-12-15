/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:35:33 by seyun             #+#    #+#             */
/*   Updated: 2021/12/03 23:53:41 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define TITLE "cub3D"
# define EMPTY '0'
# define WALL '1'

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define FLOOR 4
# define CEILING 5

# define PI 3.1415926535897
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_ESC 53

# define MAP_START -1
# define EMPTY_LINE '\0'

typedef struct s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	double		wall_x;
	double		step;
	double		tex_pos;
	int			tex_x;
	int			tex_y;
}				t_ray;

typedef struct s_tex
{
	char		*path[5];
	int			tile[5][TEX_HEIGHT * TEX_WIDTH];
	int			floor;
	int			ceiling;
}				t_tex;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	char		dir;
}				t_player;

typedef struct s_img
{
	void		*ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			fd;
	t_tex		tex;
	t_list		*lst;
	t_img		img;
	t_player	player;
	t_ray		ray;
	int			map_width;
	int			map_height;
	char		*line;
	char		**map;
	int			**buf;
	int			width;
	int			height;
}				t_game;

/* cub3d */

void	init_game(t_game *game);
int		main(int argc, char **argv);
void	open_cub(char *file_name, t_game *game);

/* 01_read_info */

void	read_info(t_game *game);
int		decide_info_map(t_game *game, char **info);
void	game_texture(t_game *game, char *xpm_path, int flang);
void	game_color(t_game *game, char *rgb_with_comma, int flag);

/* 02_validate_info_map */

void	validate_info(t_game *game);
void	validate_map_vertical(char **map, int width, int height);
void	validate_map_horizontal(char **map, int width, int height);
void	validate_map(t_game *game);

/* 03_read_map */

void	read_map(t_game *game, char *line);
void	create_player(t_game *game, int i, int j);
void	store_map(t_game *game, t_list *curr);
void	allocate_map(t_game *game, t_list *curr);

/* 04_rearrange_game */

void	rearrange_game(t_game *game);
void	apply_player_orientation(t_game *game);
void	load_image(t_game *game, int *texture, char *path, t_img *img);
void	load_texture(t_game *game);
void	allocate_buffer(t_game *game);

/* 05_run_game */

void	run_game(t_game *game);
void	rotate_player(t_player *player, double rot_speed);
void	move_left_right(t_game *game, t_player *player, double move_speed);
void	move_back_forward(t_game *game, t_player *player, double move_speed);
int		detect_keypress(int key, t_game *game);

/* 06_execute_ray */

int		execute_ray(t_game *game);
void	ray_background(t_game *game);
void	render(t_game *game);

/* 07_set_background */

void	set_floor_ceiling_color(t_game *game);
void	set_wall_color(t_game *game, t_ray *ray, int x);
void	set_wall_texture(t_player *player, t_ray *ray);

/* 08_ray_background */

void	calculate_wall_distance(t_player *player, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	calculate_step_direction(t_player *player, t_ray *ray);
void	calculate_wall_height(t_game *game, t_ray *ray);
void	init_ray(t_game *game, t_player *player, t_ray *ray, int x);

#endif
