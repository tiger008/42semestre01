/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 09:01:47 by tperraut          #+#    #+#             */
/*   Updated: 2016/08/29 12:56:25 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

#include <math.h>

void	pt_new(t_pt *p, int x, int y, int z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

void	pt_inv(t_pt *p)
{
	pt_new(p, p->y, p->x, p->z);
}

void	pt_iso(t_pt *p, int bw)
{
	double	x;
	double	y;

	x = 10 * ((sqrt(2) / 2) * (p->x - p->y) + (double)bw);
	y = 10 * (p->z / 5 - (sqrt(2) / 4) * (p->x + p->y) + (double)bw);
	pt_new(p, (int)nearbyint(x), (int)nearbyint(y), p->z);
}
