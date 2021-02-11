/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   va_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/30 19:38:45 by oswin         #+#    #+#                 */
/*   Updated: 2021/02/11 21:57:25 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_atoi(char *nbr)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	if (nbr[0] == '-')
		i++;
	while (ft_included(nbr[i], "0123456789"))
	{
		n = n * 10 + nbr[i] - '0';
		i++;
	}
	return (n);
}

int		ft_width(char *format, va_list *ap)
{
	if (*format == '-')
		format++;
	while (*format == '0')
		format++;
	if (*format == '*')
		return (va_arg(*ap, int)); //changes
	return (ft_atoi(format));
}

int		ft_precision(char *format, va_list *ap)
{
	while (!ft_included(*format, ".cspdiux"))
		format++;
	if (*format == '.' && format[1] == '*')
		return (va_arg(*ap, unsigned int));
	if (*format == '.' && !ft_included(*(format + 1), "0123456789"))		//more changes
		return (-1);
	return (ft_atoi(format + 1));
}

void	ft_putwidth(int width, int c)
{
	int		d;

	if (c == 48)
		d = c;
	else
		d = 32;
	while (width > 0)
	{
		ft_putchar(d);
		width--;
	}
}
