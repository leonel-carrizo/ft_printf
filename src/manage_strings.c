/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:31:16 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/02/01 21:42:22 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	while (*s)
		len += (write(1, s++, 1));
	return (len);
}

int	ft_printaddr(void *ptr, char format)
{
	int	len;
	unsigned long	n;

	if (!ptr)
		return (ft_putstr("(nil)"));
	len = 0;
	len += ft_putstr("0x");
	if (ptr == 0)
		len += ft_putchar('0');
	n = (unsigned long)ptr;
	len += ft_printhexa(n, format);
	return (len);
}
