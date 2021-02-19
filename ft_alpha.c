/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_alpha.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 15:01:50 by oswin         #+#    #+#                 */
/*   Updated: 2021/02/19 10:13:41 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putc(va_list *ap, char **format, int mod)
{
	int		width;
	int		c;
	int		right;

	width = ft_width(*format + 1, ap, &right);
	if (!mod)
		c = va_arg(*ap, int);
	else
		c = '%';
	if (width)
		width--;
	if ((*format)[1] == '-' || right)
	{
		ft_putchar(c);
		ft_putwidth(width, ' ');
		return (width + 1);
	}
	ft_putwidth(width, (*format)[1]);
	ft_putchar(c);
	return (width + 1);
}

int		ft_puts(va_list *ap, char **format, char *null)
{
	int		width;
	int		precision;
	int		len;
	char	*s;
	int		right;

	right = 0;
	width = ft_width(*format + 1, ap, &right);
	precision = ft_precision(*format, ap);
	s = va_arg(*ap, char *);
	if (!s)
		s = null;
	len = ft_strlen(s);
	if (precision < len && precision >= 0)
		len = precision;
	if ((*format)[1] == '-' || right)
	{
		write(1, s, len);
		ft_putwidth(width - len, ' ');
		return (ft_retour(width, len));
	}
	ft_putwidth(width - len, (*format)[1]);
	write(1, s, len);
	return (ft_retour(width, len));
}
