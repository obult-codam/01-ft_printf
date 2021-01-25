/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstring.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 11:21:58 by oswin         #+#    #+#                 */
/*   Updated: 2021/01/25 11:24:51 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
