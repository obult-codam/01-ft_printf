/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_alpha.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 15:01:50 by oswin         #+#    #+#                 */
/*   Updated: 2021/01/30 23:12:44 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		putc(va_list *ap, char **format)
{
	int		width;
	char	c;

	width = ft_width(*format + 1, ap);
	c = va_arg(*ap, char);
	if (width)
		width--;
	if (*format[1] == '-')
	{
		ft_putchar(c);
		ft_putwidth(width, ' ');
	}
	else
	{
		ft_putwidth(width, ' ');
		ft_putchar(c);
	}
	return (width + 1);
}

int		ft_puts(va_list *ap, char **format)
{
	int		width;
	int		len;
	int		s_len;
	char	*s;

	width = ft_width(*format + 1, ap);
	len = ft_precision(format, ap);
	s = va_arg(*ap, char *);
	s_len = ft_strlen(s);
	if (len < s_len && len != -1)
		s_len = len;
	if (*format[1] == '-')
	{
		write(1, s, s_len);
		ft_putwidth(width - s_len, ' ');
	}
	else
	{
		ft_putwidth(width - s_len, ' ');
		write(1, s, s_len);
	}
	if (width > s_len)
		return (width);
	return (s_len);
}
