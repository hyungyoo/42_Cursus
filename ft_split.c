#include "libft.h"

int	ft_tab_count(char const *s, char c)
{
	int	i;
	int	count;
	int	tmp;

	i = 0;
	count = 0;
	tmp = 0;
	if (s == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			tmp = 0;
		else if (tmp == 0)
		{
			tmp = 1;
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_tab_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_tab_free(char const **s, int i)
{
	while (i > 0)
	{
		i--;
		free((void *)s[i]);
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**new;

	i = 0;
	j = 0;
	new = (char **)malloc(sizeof(char *) * (ft_tab_count(s, c) + 1));
	if (!(new))
		return (NULL);
	while (s[i] != '\0' && j < ft_tab_count(s, c))
	{
		while (s[i] == c)
			i++;
		k = 0;
		new[j] = (char *)malloc(ft_tab_len(s, c, i) + 1);
		if (!(new[i]))
			return (ft_tab_free((char const **)new, j));
		while (s[i] != '\0' && s[i] != c)
			new[j][k++] = s[i++];
		new[j][k] = '\0';
		j++;
	}
	new[j] = 0;
	return (new);
}
