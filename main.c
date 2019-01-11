/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:10:37 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/11 15:55:20 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_arg(char *str, t_all *all)
{
	int		i;
	int		sum;
	int		save;

	sum = 0;
	i = 1;
	while (str[i])
	{
		save = sum;
		all->R += (str[i] == 'R' ? 1 : 0);
		all->l += (str[i] == 'l' ? 1 : 0);
		all->r += (str[i] == 'r' ? 1 : 0);
		all->t += (str[i] == 't' ? 1 : 0);
		all->a += (str[i] == 'a' ? 1 : 0);
		sum = all->R + all->l + all->r + all->t + all->a;
		if (sum == save)
		{
			all->badchar = str[i];
			return (-1);
		}
		i++;
	}
	return (0);
}

int		ft_count_files(t_all *all)
{
	if (!(all->fd2 = opendir((const char *)("."))))
		return (-1);
	while ((all->ptr = readdir(all->fd2)) != NULL)
	{
		if (all->ptr->d_type == DT_REG)
			all->nbrfile++;
		if (all->ptr->d_type == DT_DIR)
			all->nbrdir++;
	}
	closedir(all->fd2);
	return (1);
}

int		create_current(t_all *all, int nbf, int nbd)
{
	int	i;
	int	a;
	int	b;

	b = 0;
	a = 0;
	i = 0;
	if (!(all->regf = (char **)malloc(sizeof(char *) * (nbf + 1))))
		return (-1);
	all->regf[nbf + 1] = NULL;
	if (!(all->dir = (char **)malloc(sizeof(char *) * (nbd + 1))))
		return (-1);
	all->dir[nbd + 1] = NULL;
	if (!(all->fd2 = opendir((const char *)("."))))
		return (-1);
	while (i < (nbf + nbd))
	{
		all->ptr = readdir(all->fd2);
		if (all->ptr->d_type == DT_REG)
		{
			if (!(all->regf[a] = (char *)malloc(sizeof(char) * ft_strlen(all->ptr->d_name))))
				return (-1);
			//			printf("FICHIER %s\n", all->ptr->d_name);
			all->regf[a] = all->ptr->d_name;
			a++;
		}
		else if (all->ptr->d_type ==  DT_DIR)
		{
			if (!(all->dir[b] = (char *)malloc(sizeof(char) * ft_strlen(all->ptr->d_name))))
				return (-1);
			//			printf("DOSSIER %s\n", all->ptr->d_name);
			all->dir[b] = all->ptr->d_name;
			b++;
		}
		i++;
	}
	closedir(all->fd2);
	return(0);
}

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

int main(int argc, char **argv)
{
	t_all	all;
	int		i;

	i = 1;
	ft_init(&all);
	if (argc)
	{
		if (argc > 1 && argv[1][0] == '-')
		{
			if (get_arg(argv[1], &all) == -1)
				return (ft_error(0, &all));
		}
		else if (argc > 1 && argv[1][0] != '-')
		{
			if (!(all.fd = (int *)malloc(sizeof(int) * (argc - 1))))
				return (-1);
			while (i < (argc))
			{
				all.fd[i - 1] = open(argv[i], O_RDONLY);
				i++;
			}
			just_files(&all, argv, argc);
			return (0);
		}
		ft_count_files(&all);
		printf("nbr fichier =%d nbr dir =%d\n", all.nbrfile, all.nbrdir);
		create_current(&all, all.nbrfile, all.nbrdir);
		zeroac(&all);
		ft_displays(&all, 0);
		return (0);
	}
/*	if (argv[1][0] != '-')
	{
		if (!(all.fd = (int *)malloc(sizeof(int) * (argc - 1))))
			return (-1);
		while (i < (argc))
		{
			all.fd[i - 1] = open(argv[i], O_RDONLY);
			i++;
		}
		just_files(&all, argv, argc);
		return (0);
	}
	else
	{
		if (get_arg(argv[1], &all) == -1)
			return (ft_error(0, &all));
		//		data(argv, argc, &all);
	}*/
	return (0);
}
