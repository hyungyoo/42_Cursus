#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	
	char **str = (char **)malloc(sizeof(char *) * 3);

	
	str[0] = (char *)malloc(sizeof(char) * 3);
	str[1] = (char *)malloc(sizeof(char) * 3);
	
	str[1][0] = 'a';
	str[1][1] = 'a';
	str[1][2] = '\0';
	
	str[2][0] = 'b';
	str[2][1] = 'b';
	str[2][2] = '\0';

	/*
	int	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	*/
	return (0);
}
