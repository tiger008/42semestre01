/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:56:26 by tperraut          #+#    #+#             */
/*   Updated: 2016/02/23 17:11:38 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

#include <fcntl.h>

static void sq_init(int *sq_size, int size)
{
	*sq_size = ft_sqrt(size * 4);
	if (*sq_size * *sq_size < size * 4)
		++*sq_size;
}

static void freetwo(char ***p_sol, t_trio **pa_trio, int sq_size)
{
	if (*p_sol)
		ft_free_mat(p_sol, sq_size + 1);
	free(*pa_trio);
}
int		main(int argc, char **argv)
{
	int		fd;
	int		len;
	t_trio	*a_trio;
	char	**sol;
	int		sq_size;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != ER)
		{
			if ((len = parser(fd, &a_trio)) == ER || len == 0)
				ft_putendl("error");
			else
			{
				sq_init(&sq_size, len);
				sol = ft_resolve(a_trio, len, &sq_size);
				ft_affiche(sol);
				freetwo(&sol, &a_trio, sq_size);
			}
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("usage: ./fillit file");
	return (0);
}
