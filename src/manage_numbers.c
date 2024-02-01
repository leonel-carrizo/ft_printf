/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:30:40 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/02/01 22:05:42 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnumber(long nbr)
{
	long long	n;
	char	c[10];
	int	i;
	int	count;

	n = nbr;
	i = 0;
	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		n *= -1;
		count += write(1, "-", 1);
	}
	while (n)
	{
		c[i++] = n % 10 + '0';
		n /= 10;
	}
	while (i > 0)
		count += write(1, &c[--i], 1);
	return(count);
}

int	ft_printhexa(unsigned long nbr, char format)
{
	int	n;
	const char	*base;
	char	hex[16];
	int	i;
	int	rem;

	if (format == 'X')
		base ="0123456789ABCDEF";
	base = "0123456789abcdef";
	i = 0;
	n = 0;
	if ((long long int)nbr < 9)
		return (ft_putchar(nbr + '0'));
	while ((long long int)nbr)
	{
		rem = nbr % 16;
		hex[i++] = base[rem];
		nbr /= 16;
	}
	while (i > 0)
		n += write(1, &hex[--i], 1);
	return (n);
}
