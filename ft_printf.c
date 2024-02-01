/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:19:57 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/02/01 21:52:43 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/* check which specifiers and handles in according to each case  */
static int	ft_check_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		 return (ft_putnumber((long)va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnumber((long)va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_printhexa(va_arg(args, unsigned long), format));
	else if (format == 'p')
		return (ft_printaddr(va_arg(args, void *), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

/* Produce output according to a format and write output to stdout, */
int	ft_printf(const char *format, ...)
{
	// Handling variable arguments. (macros)
	va_list args;
	int	nprint;

	nprint = 0;
	va_start(args, format);
	// handling differents types of formats specifiers.
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			nprint += ft_check_format(*format, args);
		}
		else
			nprint += write(1, format, 1);
		format++;
	}
	va_end(args);
	// return number of characters printed.
	return (nprint);
}

int	main(void)
{
	int	i;
	int	j;
	char *mem = malloc(sizeof(int) + 2);

	i = 0;
	j = 0;
	mem = "HH";
	i = ft_printf("F=  %p\n%s\n", mem, mem);
	j =    printf("C=  %p\n%s\n", mem, mem);
	printf("C print:%d\nFT print:%d\n", j, i);

	return (0);
}

/********************************************************************************
ft_printf("char %c, string %s, numero %d", Char, string, decimal);

RETURN VALUES:
if succes:
	Return number of characters printed excludin '\0'
if error:
	Return negative value.Implementation conversions:

FORMAT CONVERSIONS:
• %% Prints a percent sign.
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %d Prints a decimal (base 10) number.:call ToggleHighlightLongLines()
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %p The void * pointer argument has to be printed in hexadecimal format.
*******************************************************************************/
