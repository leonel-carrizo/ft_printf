/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:19:57 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/30 22:16:57 by lcarrizo         ###   ########.fr       */
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
	else if (format == 'd')
		 return (ft_putnumber(va_arg(args, int)));
	else if (format == 'u')
		return 0;
	else if (format == 'i')
		return 0;
	else if (format == 'x')
		return 0;
	else if (format == 'X')
		return 0;
	else if (format == 'p')
		return 0;
	else if (format == '%')
		return (write(1, "%", 1));
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
	char	cha;
	char	*word;
	int	n;

	i = 0;
	j = 0;
	word = "How are you";
	n = INT_MIN;
	cha = 'W';
	i = ft_printf("F: \%\% Hello %% cruel %% world:\n%c\n%s\n%d\n", cha, word, n);
	j = printf("C: \%\% Hello %% cruel %% world:\n%c\n%s\n%d\n", cha, word, n);
	printf("C: %d\nFT:%d\n", j, i);

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
