/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:40:54 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/12 13:15:16 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		print_ls(t_all *all)
{
	ft_count_files(all);
	create_current(all, all->nbrfile, all->nbrdir);
	ft_displays(all, 0);
	return (0);
}

int		print_bad_files(t_all *all, int y, int start, char **argv)
{
	while (y > start)
	{
		if ((all->df = open(argv[y], O_RDONLY)) < 0)
		{
			ft_putstr("ls : ");
			ft_putstr(argv[y]);
			ft_putstr(": No such file or directory\n");
		}
		y--;
	}
	return (0);
}

int		print_good_files(t_all *all, int y, int start, char **argv)
{
	while (y > start)
	{
		if ((all->df = open(argv[y], O_RDONLY)) > 0)
		{
			ft_putstr(argv[y]);
			ft_putchar('\n');
		}
		y--;
	}
	return (0);
}
