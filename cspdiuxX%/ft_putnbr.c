/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 11:36:39 by oswin         #+#    #+#                 */
/*   Updated: 2021/01/30 23:07:24 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


//no negatives! (size_t)
//it can do all!!!
//input sanitasion? what is that?

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr_b(size_t input, char *base, int blen)
{
	if (input >= 0 && input < blen)
		ft_putchar(base[input]);
	else
	{
		ft_putnbr_b(input / blen, base, blen);
		ft_putchar(base[input % blen]);
	}
}





int		main(void)
{
	int q = -214483648;
	ft_putnbr_b(-1 * (size_t)q, "0123456789", 10);
	ft_putchar('\n');
	ft_putnbr_b(21474836480808080, "0123456789abcdef", 10);
	ft_putchar('\n');
	printf("%x\n", 33);
	printf("%01.3d\n", -30);
	int i = 252645135;
	int b = 986895;
	printf("%7.0s\n", "string05");
	printf("%000*.3c\n", 3, 'a');
	return (0);
}