/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:50:27 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/25 19:08:28 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_putnbr(int nbr)
{
	size_t	count;

	count = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		count += 11;
	}
	else if (nbr >= 0 && nbr <= 9)
	{
		count += ft_putchar(nbr + '0');
	}
	else if (nbr < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr(nbr * (-1));
	}
	else
	{
		count += ft_putnbr(nbr / 10);
		count += ft_putnbr(nbr % 10);
	}
	return (count);
}

int	ft_unsigned_putnbr(unsigned int nbr)
{
	size_t	count;

	count = 0;
	if (nbr <= 9)
		count += ft_putchar(nbr + '0');
	else
	{
		count += ft_unsigned_putnbr(nbr / 10);
		count += ft_unsigned_putnbr(nbr % 10);
	}
	return (count);
}
