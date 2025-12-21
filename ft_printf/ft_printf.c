/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:23:15 by aghalmi           #+#    #+#             */
/*   Updated: 2025/11/21 16:49:14 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	count;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_printf_2(str[i + 1], args);
			i += 2;
		}
		else
			count += ft_putchar(str[i++]);
	}
	va_end(args);
	return (count);
}

int	ft_printf_2(char str, va_list args)
{
	size_t	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (str == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (str == 'u')
		count += ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (str == 'x')
		count += ft_low_hexa_putnbr(va_arg(args, unsigned int));
	else if (str == 'X')
		count += ft_upp_hexa_putnbr(va_arg(args, unsigned int));
	else if (str == 'p')
		count += ft_purcent_p(va_arg(args, void *));
	else if (str == '%')
		count += ft_purcent();
	return (count);
}
