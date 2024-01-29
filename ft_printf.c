/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:19:57 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/29 22:32:29 by lcarrizo          ###   ##london.com     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(cont char *format, ...)
{
	// Handling variable arguments. (macros)
	va_list args;
	int	nprinted;
	int	i;

	nprinted = 0;
	i = 0;
	va_start(args, format);
	// handling differents types of formats specifiers.
	while (*format)
	{
		if (*format == '%' && *(format) + 1 != '%')
		{
			//manage decimal
			nprinted += va_args()
		}
		format++;
		i++;
	}
	
	// return number of characters printed.
	va_end(args);
	return (nprinted);
}

/*
ft_printf("char %c, string %s, numero %d", Char, string, decimal);
RETURN VALUES:
if succes:
	Return number of characters printed excludin '\0'
if error:
	Return negative value.
Implementation conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

*/
