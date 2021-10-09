/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:14:47 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/09 18:16:48 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_strcmp_pivot(char *str)
{
	if (!ft_strcmp(str, "|"))
		return (1);
	else if (!ft_strcmp(str, "<"))
		return (1);
	else if (!ft_strcmp(str, "<<"))
		return (1);
	else if (!ft_strcmp(str, ">"))
		return (1);
	else if (!ft_strcmp(str, ">>"))
		return (1);
	return (0);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strjoin(s1, " ");
	free(s1);
	ret = ft_strjoin(tmp, s2);
	free(s2);
	free(tmp);
	return (ret);
}

int	ft_count_pivot(char **str)
{
	int	count_pivot;
	int	i;

	i = 0;
	count_pivot = 0;
	while (str[i])
	{
		if (ft_strcmp_pivot(str[i]))
			count_pivot++;
		i++;
	}
	return (count_pivot);
}

char	**ft_split_cmd(char **str)
{
	char **ret;

	//ret = str;
	/*
	to do
		1. num_split -- > malloc double_array
		2. get_strjoin for each multiple_cmd
			cat |>infile |
			grep hello > 
			cat outfile <
			heool
		3. ft_strcpy-> mettre dans double array et free autre 
	*/
	return (ret);
}


void	ft_print_all(char **ret)
{
	int	i = 0;
	if (!ret)
		return ;
	while (ret[i])
		printf("%s\n", ret[i++]);


void	ft_free_double(char **str)
{
	int	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	main(void)
{
	char str[100] = "cat |>infile | grep hello > cat outfile < heool";
	char str2[100] = "< cat |>infile | grep hello > cat outfile < heool";
	char **ret = ft_split_cmd(ft_split(str, ' '));
	char **ret2 = ft_split_cmd(ft_split(str2, ' '));
	
	
	printf("count_pivot = %d\n", ft_count_pivot(ret));
	printf("%s\n\n", str);
	
	printf("count_pivot2 = %d\n", ft_count_pivot(ret2));
	printf("%s\n\n", str2);
	
	ft_print_all(ret);	

	return (0);
}

/*

	if 

	split multi cmd;
	in there, multi cmd aussi! 
	cmd1 option arg m_cmd cmd2 option arg..
	
	split오류 == 
	pivot이 << >> 은 인식못함!
	그렇기때문에, 좆됨...
	DONC, avec strjoin, et avec strcmp(ret[i], < ou << ou | ou > ou >>);
	avec cela, strjoin jusqu'a multi_cmd
	아니면 check_pivot에 strcmp로 <<가 있는지 확인하는것도있는데 그건별로임..
	그리고 cmd1| 이것도 pivot으로 읽을듯
	다른방법을 찾아야함
	다 읽어가면서 앞뒤가 space이며 pivot = "|" < << > >> 인 경우를 기준으로
	split할수있는 함수가 있어야한다.
	
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	아니면 전부다 띄어쓰기로 split한것을 합쳐보면서, 만약에 | << >> > 일떄는 그것까지 합치고
	나머지는 free하는것도 방법인듯함
	좋아!

	이걸위해서는 add_split함수로 그안에있는것들을 <|<<>>>일때, 합치도록!
	strjoin함수로!

	cmd1 option arg m_cmd

	cmd2 option arg null

	

	comme ca, apres
	link all node;
	print all node for check!

	add first node in global value for free
	
	or t_parsing *ft_parsing_cmd(char *str) for free in minishell fucntion
	*/
