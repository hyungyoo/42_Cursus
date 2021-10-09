#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char **ret = (char **)malloc(sizeof(char *) * 3 + 1);
	ret[3] = NULL;
	
	char *s1 = malloc(sizeof(char) * 4);
	s1[0] = 'a';
	s1[1] = 'a';
	s1[2] = 'a';
	s1[3] = '\0';
	
	char *s2 = malloc(sizeof(char) * 4);
	s2[0] = 'b';
	s2[1] = 'b';
	s2[2] = 'b';
	s2[3] = '\0';
	
	char *s3 = malloc(sizeof(char) * 4);
	s3[0] = 'c';
	s3[1] = 'c';
	s3[2] = 'c';
	s3[3] = '\0';

	ret[0] =  s1;
	ret[1] =  s2;
	ret[2] =  s3;
	
	int i = 0;
	while (ret[i])
		printf("%s\n", ret[i++]);
	

	return (0);
}
