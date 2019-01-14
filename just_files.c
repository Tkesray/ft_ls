/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:53:10 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/14 13:29:13 by prastoin         ###   ########.fr       */
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

int		just_files_display(t_all *all, char **argv, int argc, int start)
{
	int	i;
	int	save;
	int	reading;
	int	j;

	j = 0;
	reading = 0;
	save = 0;
	i = start;
	/*	printf("BAD = %d\n", ft_count_bfd(all->fd, 0, argc - 1));
		printf("FILE = %d\n", ft_count_bfd(all->fd, 1, argc - 1));*/
	//	printf("DIR = %d\n", ft_count_bfd(all->fd, 2, argc - 1));
	while (i < argc)
	{
		//		printf("argv[i] = %s\n", argv[i]);
		if (all->fd[0][j] == -1)
		{
			save = 1;
			ft_putstr("ls : ");
			ft_putstr(argv[i]);
			ft_putstr(" No such file or directory\n");
		}
		i++;
		j++;
	}
	j = 0;
	i = start;
	while (i < argc)
	{
		//		printf("argv[i] = %s\n", argv[i]);
		if (all->fd[0][j] > 0 && all->fd[1][j] == -1)
		{
			save = 1;
			ft_putstr(argv[i]);
			ft_putchar('\n');
		}
		j++;
		i++;
	}
	j = 0;
	i = start;
	while (i < argc)
	{
		//		printf("argv[i] = %s\n", argv[i]);
		if (all->fd[0][j] > 0 && all->fd[1][j] == 1)
		{
			if (save == 1)
			{
				ft_putchar('\n');
				save = 0;
			}
			if (argc != 2)
			{
				ft_putstr(argv[i]);
				ft_putstr(":\n");
			}
			all->fd2 = opendir((const char *)argv[i]);
			while ((all->ptr = readdir(all->fd2)) != NULL)
			{
				if (all->a > 0)
				{
					ft_putstr(all->ptr->d_name);
					ft_putchar('\n');
				}
				else
				{
					if (all->ptr->d_name[0] != '.')
					{
						ft_putstr(all->ptr->d_name);
						ft_putchar('\n');
					}
				}
			}
			reading++;
			if (j != (ft_count_bfd(all->fd, 2, argc - 1) - 1))
				ft_putchar('\n');
			closedir(all->fd2);
		}
		j++;
		i++;
	}
	return (1);
}

int		just_files(t_all *all, char **argv, int argc, int start)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	if (!(all->fd[0] = (int *)malloc(sizeof(int) * (argc - start))))
		return (-1);
	if (!(all->fd[1] = (int *)malloc(sizeof(int) * (argc - start))))
		return (-1);
	while (i < (argc))
	{
		//		printf("%s\n", argv[i]);
		if (!(all->fd2 = opendir((const char *)argv[i])))
			all->fd[1][j] = -1;
		else
			all->fd[1][j] = 1;
		all->fd[0][j] = open(argv[i], O_RDONLY);
		close(all->fd[0][j]);
		if (all->fd2)
			closedir(all->fd2);
		i++;
		j++;
	}
	//	printf("all->fd[0][1] = %d et all->fd[1][0] = %d\n", all->fd[0][0], all->fd[1][0]);
	//	printf("all->fd[0][1] = %d et all->fd[1][1] = %d\n", all->fd[0][1], all->fd[1][1]);
	just_files_display(all, argv, argc, start);
	return (0);
}
