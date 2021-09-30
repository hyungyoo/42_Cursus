#include "../includes/minishell.h"

//parsing :
// to do:
//      1. " ' 가 나오면 짝수인지확인
//      2. dquote> or quote> until ctrl + c

int	ft_dquote(char *str)
{
	int	i;
	int	num_dquote;
	
	num_dquote = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
			num_dquote++;
		i++;
	}
	return (num_dquote);
}

int	ft_quote(char *str)
{
	int	i;
	int	num_quote;
	
	num_quote = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 39)
			num_quote++;
		i++;
	}
	return (num_quote);
}

int	ft_add(int num)
{
	return ((num % 2) == 0);
}

void	afficher_handler(int sig)
{
	if (sig == SIGINT)
		g_info.quit_quote = 1;
}

int	ft_afficher_quote(char *quote)
{
	char *str;

	signal(SIGINT, afficher_handler);
	while (1)
	{
		str = readline(quote);
		if (g_info.quit_quote == 1)
		{
			g_info.quit_quote = 0;
			free(str);
			break ;
		}	
		free(str);
	}
	return (1);
}

int	ft_verifier_dquote(char *str)
{
	int	num_dquote;
	int	num_quote;

	num_dquote = 0;
	num_quote = 0;
	num_dquote = ft_dquote(str);
	num_quote = ft_quote(str);
	if (!ft_add(num_dquote))
		return (ft_afficher_quote("dquote>"));
	else if (!ft_add(num_quote))
		return (ft_afficher_quote("quote>"));
	return (0);
}
	
void	parsing(char *str)
{
	ft_verifier_dquote(str);		
}
