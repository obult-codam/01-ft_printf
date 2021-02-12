/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_va_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/30 19:38:45 by oswin         #+#    #+#                 */
/*   Updated: 2021/02/12 16:17:57 by oswin         ########   odam.nl         */
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

int		ft_width(char *format, va_list *ap, int *right)
{
	int	tmp;

	if (*format == '-')
		format++;
	while (*format == '0')
		format++;
	if (*format == '*')
	{
		tmp = va_arg(*ap, int);
		if (tmp < 0)
		{
			*right = 1;
			tmp = tmp * -1;
		}
		return (tmp);
	}
	*right = 0;
	return (ft_atoi(format));
}

int		ft_precision(char *format, va_list *ap)
{
	while (!ft_included(*format, ".cspdiuxX"))
		format++;
	if (*format == '.' && format[1] == '*')
		return ((unsigned int)va_arg(*ap, int));
	if (*format == '.')
		return (ft_atoi(format + 1));
	return (-1);
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
