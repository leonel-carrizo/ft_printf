/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:30:40 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/30 22:19:36 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnumber(long nbr)
{
	int	n;

	n = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		
	}
	return(n);
}
