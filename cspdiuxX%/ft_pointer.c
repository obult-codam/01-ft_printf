/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pointer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 21:41:30 by oswin         #+#    #+#                 */
/*   Updated: 2021/02/09 13:01:29 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_prep_ptr(va_list *ap, char **format)
{
	t_prep		n;
	void		*ptr;

	n.width = ft_width(*format + 1, ap);
	n.precision = ft_precision(*format, ap);
	ptr = va_arg(*ap, void*);
	n.min = 0;
	n.zero = 32;
	n.right = 0;
	n.len = ft_writelen_b((size_t)ptr, 16);
	n.superiorlen = n.len;
	if (n.precision > n.len)
		n.superiorlen = n.precision;
	n.superiorlen = n.superiorlen + 2;
	if ((*format)[1] == '0')
		n.zero = 48;
	if ((*format)[1] == '-')
		n.right = 1;
	return (ft_pointer(n, ptr));
}

int		ft_pointer(t_prep info, void *ptr)
{
	if (info.precision > 0)
	{
		if (!info.right)
			ft_putwidth(info.width - info.superiorlen, ' ');
		ft_putstring("0x");
		ft_putwidth(info.precision - info.len, '0');
	}
	else
	{
		if (!info.right)
		{
			if (info.zero == 48)
				ft_putstring("0x");
			ft_putwidth(info.width - info.len, info.zero);
		}
		if (info.zero != 48)
			ft_putstring("0x");
	}
	ft_putnbr_b((size_t)ptr, "0123456789abcdef", 16);
	if (info.right)
		ft_putwidth(info.width - info.len, ' ');
	return (ft_retour(info.superiorlen, info.width));
}

int		ft_retour(int	a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
