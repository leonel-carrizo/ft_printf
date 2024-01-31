/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:30:40 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/31 12:10:49 by lcarrizo          ###   ##london.com     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// INT_MAX: 2147483647 
// INT_MIN: -2147483647 
// LONG_MAX: +2147483647
// LONG_MIN: -2147483647 

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
