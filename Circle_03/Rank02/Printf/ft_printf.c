#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct s_tab {
	va_list list;
	int i;
	int output;
	int width;
	int	check_precision;
	int	precision;
	char mark;
	int len;
	int neg;
	int zero_count;
}				t_tab;

void	ft_init(t_tab *tab)
{
	tab->i = 0;
	tab->output = 0;
	tab->width = 0;
	tab->check_precision = 0;
	tab->precision = 0;
	tab->mark = '\0';
	tab->len = 0;
	tab->neg = 0;
	tab->zero_count = 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_clear(t_tab *tab)
{
	tab->width = 0;
	tab->check_precision = 0;
	tab->precision = 0;
	tab->mark = '\0';
	tab->len = 0;
	tab->neg = 0;
	tab->zero_count = 0;
}

int		ft_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_nbr_len(long int nbr, long int base)
{
	int i;

	i = 1;
	while (nbr >= base)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}

int ft_nbr_len_unsigned(unsigned long int nbr, unsigned long int base)
{
	int i;

	i = 1;
	while (nbr >= base)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(long int nbr, long int base_len, char *base)
{
	if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base_len, base);
		ft_putnbr_base(nbr % base_len, base_len, base);
	}
	else
		ft_putchar(base[nbr]);
}

void	ft_putnbr_base_un(unsigned long int nbr, unsigned long int base_len, char *base)
{
	if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base_len, base);
		ft_putnbr_base(nbr % base_len, base_len, base);
	}
	else
		ft_putchar(base[nbr]);
}

void	ft_find_option(const char *str, t_tab *tab)
{
	tab->i++;
	while (str[tab->i] && !(str[tab->i] == 's' || str[tab->i] == 'd' || str[tab->i] == 'x'))
	{
		if (ft_digit(str[tab->i]))
		{
			while (ft_digit(str[tab->i]))
			{
				tab->width = (tab->width * 10) + str[tab->i] - 48;
				tab->i++;
			}
		}
		if (str[tab->i] == '.')
		{
			tab->check_precision = 1;
			tab->i++;
			while (ft_digit(str[tab->i]))
			{
				tab->precision = (tab->precision * 10) + str[tab->i] - 48;
				tab->i++;
			}
		}
	}
	tab->mark = str[tab->i];
}

void	ft_print_char(int len, char c, t_tab *tab)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar(c);
		i++;
		tab->output++;
	}
}

void	ft_printf_s(t_tab *tab)
{
	char *str;
	int	index;

	index = 0;
	str = va_arg(tab->list, char *);
	if (!str)
		str = "(null)";
	tab->len = ft_strlen(str);
	if (tab->check_precision == 1 && tab->precision < tab->len)
		tab->len = tab->precision;
	ft_print_char(tab->width - tab->len, ' ', tab);
	while (str[index] && index < tab->len)
	{
		ft_putchar(str[index]);
		index++;
	}
	tab->output += tab->len;
}

void	ft_printf_d(t_tab *tab)
{
	long nbr;

	nbr = va_arg(tab->list, int);
	if (nbr < 0)
	{
		tab->neg = 1;
		nbr *= -1;
		tab->len++;
	}
	tab->len += ft_nbr_len(nbr, 10);
	if (tab->check_precision == 1 && nbr == 0)
		tab->len = 0;
	if (tab->check_precision == 1 && tab->len < tab->precision)
	{
		if (tab->neg == 1)
			tab->zero_count = (tab->precision - tab->len) + 1;
		else
			tab->zero_count = tab->precision - tab->len;
	}
	ft_print_char(tab->width - (tab->zero_count + tab->len), ' ', tab);
	if (tab->neg == 1)
		ft_putchar('-');
	ft_print_char(tab->zero_count, '0', tab);
	if (tab->check_precision == 1 && nbr == 0)
		return ;
	ft_putnbr_base(nbr, 10, "0123456789");
	tab->output += tab->len;
}

void	ft_printf_x(t_tab *tab)
{
	unsigned int nbr;

	nbr = va_arg(tab->list, unsigned int);
	tab->len += ft_nbr_len_unsigned(nbr, 16);
	if (tab->check_precision == 1 && nbr == 0)
		tab->len = 0;
	if (tab->check_precision == 1 && tab->len < tab->precision)
		tab->zero_count = tab->precision - tab->len;
	ft_print_char(tab->width - (tab->zero_count + tab->len), ' ', tab);
	ft_print_char(tab->zero_count, '0', tab);
	if (tab->check_precision == 1 && nbr == 0)
		return ;
	ft_putnbr_base_un(nbr, 16, "0123456789abcdef");
	tab->output += tab->len;
}

int		ft_printf(const char *str, ...)
{
	t_tab tab;

	va_start(tab.list, str);
	ft_init(&tab);
	while (str[tab.i] != '\0')
	{
		if (str[tab.i + 1] && str[tab.i] == '%' && str[tab.i + 1] == '%')
		{
			ft_putchar('%');
			tab.output++;
			tab.i++;
		}
		else if (str[tab.i] == '%')
		{
			ft_find_option(str, &tab);
			if (tab.mark == 's')
				ft_printf_s(&tab);
			else if (tab.mark == 'd')
				ft_printf_d(&tab);
			else if (tab.mark == 'x')
				ft_printf_x(&tab);
		}
		else
		{
			ft_putchar(str[tab.i]);
			tab.output++;
		}
		ft_clear(&tab);
		tab.i++;
	}
	va_end(tab.list);
	return (tab.output);
}

