/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:52:33 by aghalmi           #+#    #+#             */
/*   Updated: 2025/11/14 20:17:14 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_low_hexa_putnbr(unsigned long nbr)
{
	size_t	count;
	char	*hexa_number;

	count = 0;
	hexa_number = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_low_hexa_putnbr(nbr / 16);
	count += ft_putchar(hexa_number[nbr % 16]);
	return (count);
}

int	ft_upp_hexa_putnbr(unsigned int nbr)
{
	size_t	count;
	char	*hexa_number;

	count = 0;
	hexa_number = "0123456789ABCDEF";
	if (nbr >= 16)
		count += ft_upp_hexa_putnbr(nbr / 16);
	count += ft_putchar(hexa_number[nbr % 16]);
	return (count);
}

int	ft_purcent_p(void *ptr)
{
	size_t			count;
	unsigned long	nb;

	count = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		count += 5;
	}
	else
	{
		nb = (unsigned long)ptr;
		count += ft_putstr("0x");
		count += ft_low_hexa_putnbr(nb);
	}
	return (count);
}

int	ft_purcent(void)
{
	ft_putchar('%');
	return (1);
}
