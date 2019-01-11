/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:52:35 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/11 15:13:15 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printdbchar(char **tab)
{
	int	k;

	k = -1;
	while (tab[++k])
	{
		ft_putstr(tab[k]);
		ft_putchar('\n');
	}
}

void	ft_init(t_all *all)
{
	all->R = 0;
	all->l = 0;
	all->r = 0;
	all->t = 0;
	all->a = 0;
	all->nbrfile = 0;
	return ;
}

int		ft_error(int i, t_all *all)
{
	if (i == 0)
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(all->badchar);
		ft_putstr("\nusage : ls [-Rlrta] [file ...]\n");
		return (-1);
	}
	return (0);
}
