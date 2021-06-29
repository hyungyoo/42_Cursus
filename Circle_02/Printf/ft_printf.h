/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:03:50 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/02/16 03:23:29 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define CONVERSION "cspdiuxX%"

/*
** type = cdpuxx% **
** zero = 왼쪽정렬 **
*/

typedef struct		s_flag
{
	char			type;
	int				width;
	int				zero;
	int				precision;
	int				negative;
	int				base;
	int				sign;
}					t_flag;

/*
** MAIN FUNCTION **
*/

int					ft_printf(const char *str, ...);
int					ft_parsing_str(va_list ap, char *str);
int					ft_putchar_static(char c, int target);
void				ft_init_flag(t_flag *flag);
void				ft_check_flag(va_list ap, char *str, t_flag *flag, int i);
void				ft_check_width_precision(va_list ap,
		char *str, t_flag *flag, int i);
void				ft_controleur_type(va_list ap, t_flag *flag);

/*
** FUNCTION POUR CHAR
*/

void				ft_print_char(int c, t_flag *flag);
void				ft_put_width(int width, int len, int zero);

/*
** FUNCTION POUR STR
*/

void				ft_print_str(char *str, t_flag *flag);
int					ft_parsing_buf(char **buf, char *str, int end, int len);
int					ft_put_width_str(char **buf, t_flag *flag);
char				*ft_strjoin_target(char *s1, char *s2, int free_target);

/*
** FUNCTION POUR NBR
*/

char				*ft_baseset(char type);
void				ft_print_nbr(unsigned long long nbr, t_flag *flag);
int					ft_nbrlen(unsigned long long nbr, t_flag *flag);
int					ft_put_precision_str(unsigned long long nbr,
		t_flag *flag, char **buf);
int					ft_put_negative(t_flag *flag, char **buf);
void				ft_put_negative2(int buf_len, t_flag *flag, char **buf);
int					ft_put_pointeur(char **buf);
#endif
