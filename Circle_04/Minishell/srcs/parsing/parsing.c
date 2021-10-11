/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:06:00 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/11 14:26:55 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// ft_verifier_dquote 리턴값 1이면, 오류
void	parsing(char *str)
{
	ft_parsing_cmd(str);
	/*
	   this is for echo function
	 */
	
	
	//if (ft_verifier_dquote(str))
	//	return ;
	
	
	/*
	   if quote, str doit etre ne pas considere

	*/
}
