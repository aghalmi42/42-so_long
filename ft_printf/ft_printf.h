/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:50:36 by aghalmi           #+#    #+#             */
/*   Updated: 2025/11/14 20:13:10 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_printf_2(char str, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nbr);
int	ft_unsigned_putnbr(unsigned int nbr);
int	ft_low_hexa_putnbr(unsigned long nbr);
int	ft_upp_hexa_putnbr(unsigned int nbr);
int	ft_purcent_p(void *ptr);
int	ft_purcent(void);

#endif