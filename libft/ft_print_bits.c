/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:05:57 by smakni            #+#    #+#             */
/*   Updated: 2018/05/24 13:52:28 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if (((octet >> i) & 1) == 1)
			ft_putchar('1');
		else
			ft_putchar('0');
		i--;
	}
}
