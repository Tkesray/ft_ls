/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:53:10 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/12 14:00:24 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int ft_count_bfd(int *tab[2], int i, int max)
{
	int	dir;
	int	file;
	int	bad;
	int	x;

	x = -1;
	dir = 0;
	file = 0;
	bad = 0;
	while (++x < max)
	{
		if (tab[0][x] < 0)
			bad++;
		else if (tab[0][x] > 0 && tab[1][x] == -1)
			file++;
		else if (tab[0][x] > 0 && tab[1][x] == 1)
			dir++;
	}
	if (i == 0)
		return (bad);
	else if (i == 1)
		return (file);
	return (dir);
}

int		just_files_display(t_all *all, char **argv, int argc)
{
	int	i;
	int	save;
	int	reading;

	reading = 0;
	save = 0;
	i = 0;
	printf("BAD = %d\n", ft_count_bfd(all->fd, 0, argc - 1));
	printf("FILE = %d\n", ft_count_bfd(all->fd, 1, argc - 1));
	printf("DIR = %d\n", ft_count_bfd(all->fd, 2, argc - 1));
	while (i < argc - 1)
	{
		if (all->fd[0][i] == -1)
		{
			ft_putstr("ls : ");
			ft_putstr(argv[i + 1]);
			ft_putstr(" No such file or directory\n");
		}
		i++;
		save = 1;
	}
	i = 0;
	while (i < argc - 1)
	{
		if (all->fd[0][i] > 0 && all->fd[1][i] == -1)
		{
			ft_putstr(argv[i + 1]);
			ft_putchar('\n');
		}
		i++;
		save = 1;
	}
	i = 0;
	while (i < argc - 1)
	{
		if (all->fd[0][i] > 0 && all->fd[1][i] == 1)
		{
			if (argc != 2)
			{
				ft_putstr(argv[i + 1]);
				ft_putstr(":\n");
			}
			all->fd2 = opendir((const char *)argv[i + 1]);
			while ((all->ptr = readdir(all->fd2)) != NULL)
			{
				if(all->ptr->d_name[0] != '.')
				{
					ft_putstr(all->ptr->d_name);
					ft_putchar('\n');
				}
				reading++;
			}
			if (i != (ft_count_bfd(all->fd, 2, argc - 1)))
				ft_putchar('\n');
			reading = 0;
		}
		i++;
	}
	return (1);
}

int		just_files(t_all *all, char **argv, int argc)
{
	int	i;

	i = 1;
	if (!(all->fd[0] = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	if (!(all->fd[1] = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	while (i < (argc))
	{
		if (!(all->fd2 = opendir((const char *)argv[i])))
			all->fd[1][i - 1] = -1;
		else
			all->fd[1][i - 1] = 1;
		all->fd[0][i - 1] = open(argv[i], O_RDONLY);
		close(all->fd[0][i - 1]);
		if (all->fd2)
			closedir(all->fd2);
		i++;
	}
	just_files_display(all, argv, argc);
	return (0);
}
