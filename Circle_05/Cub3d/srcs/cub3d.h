#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

# define TITLE "Welcome to Yoo's family"
# define EMPTY '0'
# define WALL '1'

# define PI 3.1415926535897
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define TEX_WIDTH 64
# define TEX_HEIGHT	64

# define KEY_A	0
# define KEY_D	2
# define KEY_S	1
# define KEY_W	13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_ESC 53

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define F 4
# define C 5

# define MAP_START -1

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
	double		wall_x;
	double		step;
	double		tex_pos;
	int			tex_x;
	int			tex_y;
}				t_ray;

typedef struct s_env
{
	char	*path[5];
	int		tex[5][TEX_WIDTH * TEX_HEIGHT];
	int		floor;
	int		ceiling;
	int		width;
	int		height;
}				t_env;

typedef struct s_player
{
	double	x;
	double	y;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	double	move_speed;
	double	rot_speed;
	char	dir;
}				t_player;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		size_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_info
{
	t_env		env;
	t_player	player;
	t_img		img;
	t_ray		ray;
	void		*mlx;
	void		*win;
	int			fd;
	int			fd_map;
	int			window_height;
	int			window_width;
	int			**render_buf;
	char		**map;
	char		*line;
}				t_info;

void	ft_strexit(char *str);

/*main.c */
void	init_info(t_info *all);
void	set_player_direction(t_info *all);

/* strip_texture_color*/
void	strip_wall_texture(t_player *player, t_ray *ray);
void	strip_wall_color(t_info *all, t_ray *ray, int x);

/*keycode.c */
int		exit_key(t_info	*all);
int		execute_keypress(int key, t_info *all);
void	go_back_forward(t_info *all, t_player *player, double move_speed);
void	go_left_right(t_info *all, t_player *player, double move_speed);

/*execute_game.c*/
void	execute_game(t_info	*all);
int		execute_ray(t_info	*all);
void	set_floor_ceiling_color(t_info *all);
void	set_ray(t_info *all);
void	render_buffer(t_info *all);

/*arrange_game.c*/
void	arrange_game(t_info	*all);
void	rotate_player(t_player *player, double rot_speed);
void	allocate_game_buf(t_info *all);
void	load_texture(t_info	*all);
void	load_image(t_info *all, int *texture, char *path, t_img *img);

/*read_map.c */
void	read_line_map(t_info *all);
int		direction_info_map(t_info *all, char **map_split);
void	floor_ceiling_color(t_info *all, char *rgb_with_comma, int flag);

/* validate_map.c */
void	validate_map(t_info *all);
void	horizontal_read_map(char **map, int width, int height);
void	vertical_read_map(char **map, int width, int height);

/*check_map.c*/
void	fd_open_error(char *file_name, t_info	*all);
void	xpm_parsing(t_info *all, char	*xpm_path, int flag);
void	check_map(t_info *all);
void	check_map_element(t_info *all);

/*allocate_map.c*/
void	allocate_map(t_info *all);
int		get_size_map(t_info *all);
bool	get_flag(char *line);
void	set_player(t_info *all, int i, int j);
char	*strdup_line(char *str, int size);

/*ray_casting*/
void	init_ray(t_info *all, t_player *player, t_ray *ray, int pixel);
void	set_side_dist(t_player *player, t_ray *ray);
void	execute_dda(t_info *all, t_ray *ray);
void	set_prep_wall_dist(t_player *player, t_ray *ray);
void	set_wall_height(t_info *all, t_ray *ray);
#endif
