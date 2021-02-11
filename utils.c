/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 12:24:15 by oswin         #+#    #+#                 */
/*   Updated: 2021/02/11 21:07:41 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_included(char to_check, char *str)
{
	while (*str)
	{
		if (*str == to_check)
			return (1);
		str++;
	}
	return (0);
}

int		ft_writelen_b(size_t nbr, int blen)
{
	int		i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr = nbr / blen;
		i++;
	}
	return (i);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstring(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}
