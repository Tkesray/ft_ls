/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:40:54 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/12 10:46:32 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		print_ls(t_all *all)
{
	ft_count_files(all);
//	printf("nbr fichier =%d nbr dir =%d\n", all.nbrfile, all.nbrdir);
	create_current(all, all->nbrfile, all->nbrdir);
	zeroac(all);
	ft_displays(all, 0);
	return (0);
}
