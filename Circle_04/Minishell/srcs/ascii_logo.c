/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_logo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:14:17 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/18 12:14:19 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ascii_logo_lol(void)
{
	ft_putstr_fd("\033[38;5;41m___  ___ __ __  __ __  ", 1);
	ft_putendl_fd("\033[38;5;41m__  __  __  ____ __    __", 1);
	ft_putstr_fd("\033[38;5;41m||\\\\//|| || ||\\ ", 1);
	ft_putendl_fd("\033[38;5;41m|| || (( \\ ||  || ||    ||    ||", 1);
	ft_putstr_fd("\033[38;5;41m|| \\/ || || ||\\\\|| ", 1);
	ft_putendl_fd("\033[38;5;41m||  \\\\  ||==|| ||==  ||    ||", 1);
	ft_putstr_fd("\033[38;5;41m||    || || || \\|| || \\_)) ||  ||", 1);
	ft_putstr_fd("\033[38;5;41m ||___ ||__| ||__|", 1);
	ft_putendl_fd("\033[0m"" @hyungyoo @keulee", 1);
}
