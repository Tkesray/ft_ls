/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:52:35 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/12 13:55:13 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*int		ft_isadir(char *str)
{
	DIR	*fd;
	struct dirent *ptr;
	
}*/

int		ft_displays(t_all *all, int i)
{
	if (i == 0)
	{
		if (all->a > 0)
		{
			printdbchar(all->dir, 1);
			printdbchar(all->regf, 1);
		}
		else
		{
			printdbchar(all->dir, 0);
			printdbchar(all->regf, 0);
		}
		return (0);
	}
	return (0);
}

void	printdbchar(char **tab, int i)
{
	int	k;

	k = -1;
	if (i == 0)
	{
		while (tab[++k])
		{
			if (tab[k][0] != '.')
			{
				ft_putstr(tab[k]);
				ft_putchar('\n');
			}
		}
		return ;
	}
	else if (i == 1)
	{
		while (tab[++k])
		{
			ft_putstr(tab[k]);
			ft_putchar('\n');
		}
		return ;
	}
}

char	**ft_sort_params(char **argv)
{
	int		i;
	char	*swap;

	i = 0;
	while (argv[i + 1])
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0 && argv[i])
		{
			swap = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = swap;
			i = 0;
		}
		i++;
	}
	return (argv);
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
