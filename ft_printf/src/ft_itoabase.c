/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:10:05 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/17 18:07:29 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libftprintf.h"

static int	ft_nbdigit(int n, int base)
{
	int	digit;

	digit = 1;
	while (n > base)
	{
		n = n / base;
		++digit;
	}
	return (digit);
}

char		*ft_itoa(int n, int base)
{
	char	*str;
	int		neg;
	int		digit;
	char	alpha[15];

	if (base < 1 || base > 16)
		return (NULL)
	if (base == 10 && n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	digit = ft_nbdigit(n);
	if (!(str = (char*)malloc(sizeof(char) * (digit + ((neg) ? 2 : 1)))))
		return (NULL);
	else
	{
		if (neg)
			str[0] = '-';
		str[digit] = '\0';
		while (digit--)
		{
			str[digit + neg] = (int)('0' + n % 10);
			n /= 10;
		}
	}
	return (str);
}
