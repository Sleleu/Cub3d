/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 00:11:55 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/26 00:32:29 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_printf(int n, int fd)
{
	long int	nb;
	char		c;
	int			len;
	int			sign;

	len = 0;
	sign = 0;
	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
		sign = 1;
	}
	if (nb > 9)
		len += ft_putnbr_printf(nb / 10, fd);
	nb = nb % 10;
	c = nb + 48;
	len++;
	write(fd, &c, 1);
	return (len + sign);
}
