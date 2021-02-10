/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/09 11:56:50 by oswin         #+#    #+#                 */
/*   Updated: 2021/02/09 12:46:18 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

typedef struct	s_prep
{
	int				width;
	int				right;
	int				precision;
	int				len;
	int				superiorlen;
	int				zero;
	int				min;
	int				nbr;
	unsigned int	usi;
}				t_prep;

int		ft_printf(const char *format, ...);
int		rnw(const char **format, int *pcount);
int		bspecial(char **format, va_list *ap);
int		wwcd(char **format, va_list *ap, char c);

int		ft_included(char to_check, char *str);
int		ft_writelen_b(size_t nbr, int blen);
int		ft_strlen(char *s);
void	ft_putstring(char *s);
void	ft_putchar(int c);

int		ft_atoi(char *nbr);
int		ft_width(char *format, va_list *ap);
int		ft_precision(char *format, va_list *ap);
void	ft_putwidth(int width, int c);

int		ft_putc(va_list *ap, char **format);
int		ft_puts(va_list *ap, char **format);

int		ft_prep_ptr(va_list *ap, char **format);
int		ft_pointer(t_prep info, void *ptr);
int		ft_retour(int	a, int b);

void	ft_putnbr_b(size_t input, char *base, int blen);
int		ft_prepdi(va_list *ap, char **format);
int		ft_putdi(t_prep info);
int		ft_putpositive(t_prep info, char *base);
int		ft_uprep(va_list *ap, char **format, char *base);

#endif
