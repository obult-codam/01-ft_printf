/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 11:36:39 by oswin         #+#    #+#                 */
/*   Updated: 2021/01/25 12:15:27 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


//no negatives! (size_t)
//it can do all!!!
//input sanitasion? what is that?

void	ft_putnbr_b(size_t input, char *base, int blen)
{
	if (input => 0 && input < blen)
		ft_putchar(base[input]);
	else
	{
		ft_putnbrb(input / blen, base, blen);
		ft_putchar(base[input % blen]); 
	}
}