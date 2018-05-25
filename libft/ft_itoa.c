/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:03:20 by smakni            #+#    #+#             */
/*   Updated: 2018/04/27 17:53:20 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	size = ft_size(n);
	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	size--;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = -n;
	}
	while (i <= size)
	{
		str[i] = (n / ft_power(10, size - i)) + '0';
		n = n % ft_power(10, size - i);
		i++;
	}
	str[i] = '\0';
	return (str);
}
