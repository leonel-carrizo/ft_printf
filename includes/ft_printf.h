/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:17:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/30 22:16:24 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>

// delete before submit
# include <stdio.h>

int		ft_printf(const char *format, ...);
int	ft_putstr(char *s);
int	ft_putchar(int	c);
int	ft_putnumber(long nbr);


#endif	
