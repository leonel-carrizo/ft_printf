/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:26:41 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/02/02 12:58:19 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
		len += (write(1, s++, 1));
	return (len);
}

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

int	ft_printaddr(void *ptr, char format)
{
	int	len;
	unsigned long long	n;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	len = 0;
	len += ft_putstr("0x");
	if (ptr == 0)
		len += ft_putchar('0');
	n = (unsigned long long)ptr;
	len += ft_printhexa(n, format);
	return (len);
}

int	ft_printhexa(unsigned long nbr, char format)
{
	int	n;
	const char	*base;
	char	hex[16];
	int	i;
	int	rem;

	base = "0123456789abcdef";
	if (format == 'X')
		base ="0123456789ABCDEF";
	i = 0;
	n = 0;
	if ((unsigned long int)nbr < 9)
		return (ft_putchar(nbr + '0'));
	while ((unsigned long int)nbr)
	{
		rem = nbr % 16;
		hex[i++] = base[rem];
		nbr /= 16;
	}
	while (i > 0)
		n += write(1, &hex[--i], 1);
	return (n);
}