/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 22:42:10 by keulee            #+#    #+#             */
/*   Updated: 2019/12/16 17:30:27 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// Outputs the integer ’n’ to the given file descriptor.
//
// Parameters
// #1. The integer to output.
// #2. The file descriptor on which to write.
//
// Return
// None
//
#include "libft.h"

void	ft_print_nbr_fd(int nbr, int fd)
{
	int	num;
	int	nbr2;

	num = 1;
	nbr2 = nbr;
	if (nbr >= 0 && nbr < 10)
		ft_putchar_fd(nbr + 48, fd);
	else
	{
		while (nbr2 >= 10)
		{
			num = num * 10;
			nbr2 = nbr2 / 10;
		}
		while (num > 0)
		{
			ft_putchar_fd(nbr / num + 48, fd);
			nbr = nbr % num;
			num = num / 10;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		ft_print_nbr_fd(n, fd);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
		ft_print_nbr_fd(n, fd);
	}
}
