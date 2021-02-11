/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 11:36:39 by oswin         #+#    #+#                 */
/*   Updated: 2021/02/11 21:27:18 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "printf.h"

void	ft_putnbr_b(size_t input, char *base, int blen)
{
	if (input >= (unsigned int)blen)
		ft_putnbr_b(input / blen, base, blen);
	ft_putchar(base[input % blen]);
}

int		ft_prepdi(va_list *ap, char **format)
{
	t_prep		n;

	n.width = ft_width(*format + 1, ap);
	n.precision = ft_precision(*format, ap);
	n.nbr = va_arg(*ap, int);
	n.usi = (unsigned int)n.nbr;
	n.min = 0;
	n.zero = 32;
	n.right = 0;
	if (n.nbr < 0)
	{
		n.len = 1 + ft_writelen_b(n.nbr * -1, 10);
		n.min = 1;
		n.superiorlen = n.len;
		if (n.precision + 1 > n.len)
			n.superiorlen = n.precision + 1;
	}
	else
	{
		n.len = ft_writelen_b(n.nbr, 10);
		n.superiorlen = n.len;
		if (n.precision > n.len)
			n.superiorlen = n.precision;
	}
	if ((*format)[1] == '0')
		n.zero = 48;
	if ((*format)[1] == '-' || (*format)[2] == '-')
		n.right = 1;
	return (ft_putdi(n));
}

int		ft_putdi(t_prep info)
{
	if (info.min)
	{
		if (info.precision > 0)
		{
			if (!info.right)
				ft_putwidth(info.width - info.superiorlen, ' ');
			ft_putchar('-');
			ft_putwidth(info.precision - info.len + 1, '0');
		}
		else
			if (!info.right)
			{
				if (info.zero == 48)
					ft_putchar('-');
				ft_putwidth(info.width - info.len, info.zero);
			}
		if (info.zero != 48 && info.precision <= 0)
			ft_putchar('-');
		ft_putnbr_b((unsigned int)(-1 * info.nbr), "0123456789", 10);
		if (info.right)
			ft_putwidth(info.width - info.superiorlen, ' ');
		return (ft_retour(info.superiorlen, info.width));
	}
	return(ft_putpositive(info, "0123456789"));
}

int		ft_putpositive(t_prep info, char *base)
{
	if (info.precision > 0)
	{
		if (!info.right)
			ft_putwidth(info.width - info.superiorlen, ' ');
		ft_putwidth(info.precision - info.len, '0');
	}
	else
		if (!info.right)
			ft_putwidth(info.width - info.len, info.zero);
	if (!info.usi && !info.precision)
		ft_putnbr_b(info.usi, base, ft_strlen(base));		//last change
	if (info.right)
		ft_putwidth(info.width - info.superiorlen, ' ');
	return (ft_retour(info.superiorlen, info.width));
}

int		ft_uprep(va_list *ap, char **format, char *base)
{
	t_prep		n;

	n.width = ft_width(*format + 1, ap);
	n.precision = ft_precision(*format, ap);
	n.usi = va_arg(*ap, unsigned int);
	n.zero = 32;
	n.right = 0;
	n.len = ft_writelen_b(n.usi, ft_strlen(base));
	n.superiorlen = n.len;
	if (n.precision > n.len)
		n.superiorlen = n.precision;
	if ((*format)[1] == '0')
		n.zero = 48;
	if ((*format)[1] == '-' || (*format)[2] == '-')
		n.right = 1;
	return (ft_putpositive(n, base));
}
