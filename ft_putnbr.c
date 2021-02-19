/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 11:36:39 by oswin         #+#    #+#                 */
/*   Updated: 2021/02/19 11:35:56 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_b(size_t input, char *base, int blen)
{
	if (input >= (unsigned int)blen)
		ft_putnbr_b(input / blen, base, blen);
	ft_putchar(base[input % blen]);
}

int		ft_putpositive(t_prep info, char *base)
{
	if (info.precision >= 0)
	{
		if (!info.right)
			ft_putwidth(info.width - info.superiorlen, ' ');
		ft_putwidth(info.precision - info.len, '0');
	}
	else if (!info.right)
		ft_putwidth(info.width - info.len, info.zero);
	if (info.usi || info.precision)
		ft_putnbr_b(info.usi, base, ft_strlen(base));
	if (info.right)
		ft_putwidth(info.width - info.superiorlen, ' ');
	return (ft_retour(info.superiorlen, info.width));
}

int		ft_uprep(va_list *ap, char **format, char *base)
{
	t_prep		n;

	n.right = 0;
	n.width = ft_width(*format + 1, ap, &(n.right));
	n.precision = ft_precision(*format, ap);
	n.usi = va_arg(*ap, unsigned int);
	n.zero = 32;
	n.len = ft_writelen_b(n.usi, ft_strlen(base));
	n.superiorlen = n.len;
	if (n.precision > n.len)
		n.superiorlen = n.precision;
	if ((*format)[1] == '0')
		n.zero = 48;
	if ((*format)[1] == '-' || (*format)[2] == '-')
		n.right = 1;
	if (n.precision == 0 && n.usi == 0)
	{
		n.len = 0;
		n.superiorlen = 0;
	}
	return (ft_putpositive(n, base));
}
