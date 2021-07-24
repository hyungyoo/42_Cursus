#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "./mlx_linux/mlx.h"
# include "./libft/libft.h"

# define TITLE					"CUB3D"
# define TEX_WIDTH				64
# define TEX_HEIGHT				64

# define PI						3.1415926535897

# define ON						1
# define OFF					0

# define BUFFER_SIZE 			1

# define X_EVENT_KEY_PRESS 		2
# define X_EVENT_KEY_EXIT 		33

# define KEY_ESC 				65307
# define KEY_W 					119
# define KEY_A 					97
# define KEY_S 					115
# define KEY_D 					100
# define KEY_LEFT 				65361
# define KEY_RIGHT 				65363

# define DIRECTION 				"NSEW"
# define TEXTURE 				4
# define TEX_NORTH 				0
# define TEX_SOUTH 				1
# define TEX_WEST 				2
# define TEX_EAST 				3
# define RESOLUTION 			6
# define FLOOR 					7
# define CEILING				8
# define MAP 					9

typedef struct s_ray{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perp_walldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			draw_start;
	int			draw_end;
	int			color;
	int			line_height;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	int			endpoint_x;
	int			endpoint_y;
}				t_ray;

typedef struct s_info{
	char		*line;
	int			mark;
	int			win_width;
	int			win_height;
	int			floor_color;
	int			ceiling_color;
	char		*tex_path[TEXTURE];
	int			texture[TEXTURE][TEX_HEIGHT * TEX_WIDTH];
}				t_info;

typedef struct s_player {
	double		x;
	double		y;
	char		dir;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rotation_speed;
}				t_player;

typedef struct s_img {
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_map{
	char		*tmp;
	char		**buff;
	char		**map;
	int			width_count;
	int			height_count;
}				t_map;

typedef struct s_game{
	void		*mlx;
	void		*win;
	int			fd;
	t_info		info;
	t_map		map;
	t_img		img;
	t_player	player;
	t_ray		ray;
	int			**buf;
	double		*z_buffer;
}				t_game;

void			game_set_go(t_game *game);

int				get_next_line(int fd, char **line);

void			file_validation_check(int ac, char **av);
void			info_validation_check(t_game *game);
void			linux_resolution_max_min_check(t_game *game);

void			all_init(t_game *game);
void			init_map(t_game *game);
void			init_player(t_game *game);
void			game_init(t_game *game);

void			find_info(t_game *game, char **av);
int				find_and_store_info(t_game *game, char *line);
int				store_texture(int texture, t_game *game, char *line);
int				store_resolution(t_game *game, char *line);
void			find_resolution(t_game *game, char *line, int *i);
int				store_color(int info, t_game *game, char *line);
void			check_color_line(t_game *game, char *line, int *info, int *i);
void			find_color(char *line, int *i, char **rgb, int *color);

void			read_map(t_game *game, char *line);
void			find_map_width_and_height(t_game *game);
void			allocate_map(t_game *game);
void			complet_map(t_game *game);
char			*tmp_map_update(char *first_map_line, char *line);
int				player_check(char c, char *player);
void			create_player(t_game *game, int i, int j);
void			put_player_position(t_game *game);
void			rotate_player(t_player *player, double rotation_speed);

void			map_validation_check(t_game *game);
void			horizontal_lines_map_check(t_game *game);
void			vertical_lines_map_check(t_game *game);

void			ray_processing(t_game *game);
void			init_ray(t_game *game, int x);
void			calculate_ray_pos_and_dir(t_game *game);
void			set_dda(t_game *game);
void			calculate_dist_to_wall(t_game *game);
void			draw_ray_per_line(t_game *game);
void			ray_wall_draw(t_game *game, int x);

int				ft_exit_key(t_game *game);
void			error_msg(char *str);
void			exit_msg(char *str);
void			free_tab2(char **tab);
double			degree_to_radian(double degree);

int				map_component_check(char *line);
int				empty_line_check(char *line);
void			malloc_buffer(t_game *game);
void			malloc_z_buffer(t_game *game);

int				ft_keypress(int key, t_game *game);
void			rotate_left(t_player *player);
void			rotate_right(t_player *player);

void			move_forward(t_game *game, t_player *player);
void			move_backward(t_game *game, t_player *player);
void			move_left(t_game *game, t_player *player);
void			move_right(t_game *game, t_player *player);

void			render_ceiling_and_floor(t_game *game);
void			render_screen(t_game *game);

void			load_texture(t_game *game);
void			load_img(t_game *game, int *texture, char *path, t_img *img);

#endif
