/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:27:33 by sleleu            #+#    #+#             */
/*   Updated: 2022/07/06 16:48:39 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_putuint(unsigned int nb)
{
	char	c;
	int		len;

	len = 0;
	if (nb > 9)
	{
		len += ft_putuint(nb / 10);
	}
	nb = nb % 10;
	c = nb + '0';
	len++;
	ft_putchar_printf(c, 1);
	return (len);
}

static int	ft_puthex(unsigned int nb, char c)
{
	char	*index_1;
	char	*index_2;
	int		len;

	len = 0;
	index_1 = "0123456789abcdef";
	index_2 = "0123456789ABCDEF";
	if (nb > 15)
	{
		len += ft_puthex(nb / 16, c);
	}
	nb = nb % 16;
	len++;
	if (c == 'x')
		ft_putchar_printf(index_1[nb], 1);
	else if (c == 'X')
		ft_putchar_printf(index_2[nb], 1);
	return (len);
}

static int	ft_putaddr(unsigned long nb)
{
	char	*index;
	int		len;

	len = 0;
	index = "0123456789abcdef";
	if (nb == 0)
	{
		len = ft_putstr_printf(PTR_NULL, 1);
		return (len);
	}
	if (nb > 15)
	{
		len += ft_putaddr(nb / 16);
	}
	nb = nb % 16;
	len++;
	ft_putchar_printf(index[nb], 1);
	return (len);
}

int	ft_format(const char *format, va_list args)
{
	int				len;
	unsigned long	p;

	len = 0;
	if (*format == 'd' || *format == 'i')
		len = ft_putnbr_printf(va_arg(args, int), 1);
	else if (*format == 'u')
		len = ft_putuint(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		len = ft_puthex(va_arg(args, unsigned int), *format);
	else if (*format == 'p')
	{
		p = va_arg(args, unsigned long);
		if (p != 0)
			len = ft_putstr_printf("0x", 1);
		len += ft_putaddr(p);
	}
	else if (*format == 'c')
		len = ft_putchar_printf(va_arg(args, int), 1);
	else if (*format == '%')
		len = ft_putchar_printf('%', 1);
	else if (*format == 's')
		len = ft_putstr_printf(va_arg(args, char *), 1);
	return (len);
}
