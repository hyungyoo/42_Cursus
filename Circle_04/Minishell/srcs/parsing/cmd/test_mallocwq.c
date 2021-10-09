#include <stdio.h>
#include <stdlib.h>
#include "../../../includes/minishell.h"

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
	
	int	j = 1;
	i = 0;
	int	k = 0;
	if (j == 0 && k++)
		printf("in if \n");
	printf("%d == 0\n", k);
	if (i == 0 && k++)
		printf("in if \n");
	printf("%d == 1\n", k);


	printf("ret 0 == %s\n", ret[0]);
	printf("ret 1 == %s\n", ret[1]);
	printf("ret 2 == %s\n", ret[2]);
	
	char *test;
	test = ret[0];
	test = ft_strjoin(test, ret[1]);
	test = ft_strjoin(test, ret[2]);
	
	printf("test == aaabbbccc  == %s\n", test);
	return (0);
}
