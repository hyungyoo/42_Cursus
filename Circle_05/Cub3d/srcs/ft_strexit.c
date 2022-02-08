#include "cub3d.h"

void	ft_strexit(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	write(1, "\n", 1);
	exit(0);
}

/* leask 
void	ft_strexit(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	write(1, "\n", 1);
	system("leaks cub3D");
	exit(0);
}
*/
