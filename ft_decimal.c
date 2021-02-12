/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_decimal.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 13:41:44 by oswin         #+#    #+#                 */
/*   Updated: 2021/02/12 16:54:38 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_prepdi(va_list *ap, char **format)
{
	t_prep		n;

	n.right = 0;
	n.width = ft_width(*format + 1, ap, &(n.right));
	n.precision = ft_precision(*format, ap);
	n.nbr = va_arg(*ap, int);
	n.usi = (unsigned int)n.nbr;
	n.min = 0;
	n.zero = 32;
	ft_prepdi_helper(&n);
	if ((*format)[1] == '0')
		n.zero = 48;
	if ((*format)[1] == '-' || (*format)[2] == '-')
		n.right = 1;
	if (n.precision == 0 && n.usi == 0)
	{
		n.len = 0;
		n.superiorlen = 0;
	}
	return (ft_putdi(n));
}

void	ft_prepdi_helper(t_prep *p)
{
	if (p->nbr < 0)
	{
		p->len = 1 + ft_writelen_b(p->nbr * -1, 10);
		p->min = 1;
		p->superiorlen = p->len;
		if (p->precision + 1 > p->len)
			p->superiorlen = p->precision + 1;
	}
	else
	{
		p->len = ft_writelen_b(p->nbr, 10);
		p->superiorlen = p->len;
		if (p->precision > p->len)
			p->superiorlen = p->precision;
	}
}

int		ft_putdi(t_prep info)
{
	if (info.min)
		return (ft_putnegative(info));
	return (ft_putpositive(info, "0123456789"));
}

int		ft_putnegative(t_prep info)
{
	if (info.precision > 0)
	{
		if (!info.right)
			ft_putwidth(info.width - info.superiorlen, ' ');
		ft_putchar('-');
		ft_putwidth(info.precision - info.len + 1, '0');
	}
	else
	{
		if (!info.right)
		{
			if (info.zero == 48)
				ft_putchar('-');
			ft_putwidth(info.width - info.len, info.zero);
		}
	}
	if ((info.zero != 48 && info.precision <= 0)
	|| (info.right && info.precision <= 0))
		ft_putchar('-');
	ft_putnbr_b((unsigned int)(-1 * info.nbr), "0123456789", 10);
	if (info.right)
		ft_putwidth(info.width - info.superiorlen, ' ');
	return (ft_retour(info.superiorlen, info.width));
}
