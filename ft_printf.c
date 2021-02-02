/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 19:48:52 by oswin         #+#    #+#                 */
/*   Updated: 2021/01/29 22:51:36 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			pcount;
	int			tmp;

	pcount = 0;
	va_start(ap, format);
	while (rnw(&format, &pcount))
	{
		tmp = bspecial(&format, &ap);
	}
}

int		rnw(const char **format, int *pcount)
{
	int		i;

	i = 0;
	while (*format[i] && *format[i] != '%')
		i++;
	if (i)
	{
		write (1, *format, i);
		*format = *format + i;
		*pcount = *pcount + i;
	}
	return (**format);
}

int		bspecial(char **format, va_list *ap)
{
	int		i;

	i = 0;
	while (ft_included((*format)[i], "0123456789.*-"))
		i++;
	if (ft_included((*format)[i], "cspdiuxX"))
		return (wwcd(format, ap, (*format)[i]));
	else
	{
		ft_putchar('%');
		return (1);
	}
}

int		wwcd(char **format, va_list *ap, char c)
{
	if (c == 'c')
		return (ft_putc(ap, format));
	if (c == 's')
		return (ft_puts(ap, format));
	if (c == 'p')
		return (ft_putp(ap, format));
	if (c == 'd' || c == 'i')
		return (ft_putdi(ap, format)); 
	if (c == 'u')
		return (ft_putu(ap, format));
	if (c == 'x')
		return (ft_putx(ap, format));
	if (c == 'X')
		return (ft_putX(ap, format));
}