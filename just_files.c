/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:53:10 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/12 13:34:10 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		just_files_display(t_all *all, char **argv, int argc)
{
	int	i;
	int	save;
	int	reading;

	reading = 0;
	save = 0;
	i = 0;
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
			if (i != (argc - 2))
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
