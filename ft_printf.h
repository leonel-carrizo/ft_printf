/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:17:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/02/02 18:01:21 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *s);
int	ft_putchar(int c);
int	ft_putnumber(long nbr);
int	ft_printhexa(unsigned long nbr, char format);
int	ft_printaddr(void *ptr, char format);

#endif	
