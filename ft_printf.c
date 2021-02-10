/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 19:48:52 by oswin         #+#    #+#                 */
/*   Updated: 2021/02/10 21:56:06 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include "printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			pcount;
	int			tmp;

	pcount = 0;
	va_start(ap, format);
	while (rnw(&format, &pcount))
	{
		tmp = bspecial((char **)&format, &ap);
		pcount = pcount + tmp;
		while (!ft_included(*format, "cspdiuxX"))
			format++;
		format++;
	}
}

int		rnw(const char **format, int *pcount)
{
	int		i;

	i = 0;
	while ((*format)[i] && (*format)[i] != '%')
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

	i = 1;
	while (ft_included((*format)[i], "0123456789.*-"))
		i++;
	if (ft_included((*format)[i], "cspdiuxX"))
		return (wwcd(format, ap, (*format)[i]));
	else
	{
		//ft_putchar('%');
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
		return (ft_prep_ptr(ap, format));
	if (c == 'd' || c == 'i')
		return (ft_prepdi(ap, format)); 
	if (c == 'u')
		return (ft_uprep(ap, format, "0123456789"));
	if (c == 'x')
		return (ft_uprep(ap, format, "0123456789abcdef"));
	if (c == 'X')
		return (ft_uprep(ap, format, "0123456789ABCDEF"));
}

int		main(void)
{
	ft_printf("text%*.*X\n", 42, 33, 429967295);
	printf("text%*.*X\n", 42, 33, 429967295);
	return (0);
}