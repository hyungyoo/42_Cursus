/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:18:22 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/29 04:15:48 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_atoi(char *str);
int		ft_int_len(int n);
void	ft_mark(int *n, int *mark);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int		ft_isspace(char c);

#endif
