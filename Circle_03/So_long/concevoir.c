# include "so_long.h"

# define TILE_SIZE 32;

t_info	*ft_parsing_using_fd_file(char *file_name)
{
	int	fd = open(file_name, mode);
	// to do : get info in file

	/*
	map parsing;
	wall  --> array
	sprite  --> struct  x, y
	player ---> struct x, y
	*/
}

int	main(int argc, char **argv)
{
	t_info *parsing_info_map = ft_parsing_using_fd_file(file_name);
	
	setup(parsing_info_map);
	
	while (42)
		draw();
	
	return (0);
}

void	setup(t_info *parsing_info_map)
{
	// to do : initialize all objects: sprite, map, player..
	
	int	MAP_NUM_ROWS = parsing_map->num_rows;
	int	MAP_NUM_COLS = parsing_map->num_cols;

	int	WINDOW_WIDTH = MAP_NUM_ROWS * TILE_SIZE;
	int	WINDOW_HIGHT = MAP_NUM_COLS * TILE_SIZE;
	//to do :  check size  of window

}

void	update()
{
	// to do : update all game objects before we render the next frame
}

void	draw()
{
	// to do : render all objects frame by frame
	
	update();

	render();
}

void	render()
{
	int	i = 0;
	int	j;

	int	tile_x;
	int	tile_y;

	int tile_color = black_color;

	while (i < MAP_NUM_ROWS)
	{
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			tile_x = j * TILE_SIZE;
			tile_y = i * TILE_SIZE;
			if (map[i][j] == 1)
				tile_color = white_color;
			// to do : with tile_x, tile_y and tile_color, draw rect and fill color
			j++;
		}
		i++;
	}
}




