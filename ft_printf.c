/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:19:57 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/29 14:09:03 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(cont char *format, ...)
{
	// Handling variable arguments. (macro)
	va_list args;
	int	nprinted;

	nprinted = 0;
	va_start(args, format);
	nprinted = va_arg(args, int);
	// handling differents types of formats specifiers.
	

	// return number of characters printed.
	va_end(args);
	return (nprinted);
}

/*

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
