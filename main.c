/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:10:37 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/14 12:35:05 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_reset_flags(t_all *all)
{
		all->R = 0;
		all->l = 0;
		all->r = 0;
		all->t = 0;
		all->a = 0;
}

int		get_arg(char *str, t_all *all)
{
	int		i;
	int		sum;
	int		save;

	sum = 0;
	save = 0;
	i = 1;
	ft_reset_flags(all);
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

/*int		create_current(t_all *all, int nbf, int nbd)
{
	int	i;
	int	a;
	int	b;

	b = 0;
	a = 0;
	i = 0;
	if (!(all->regf = (char **)malloc(sizeof(char *) * (nbf + 1))))
		return (-1);
	all->regf[nbf] = NULL;
	if (!(all->dir = (char **)malloc(sizeof(char *) * (nbd + 1))))
		return (-1);
	all->dir[nbd] = NULL;
	if (!(all->fd2 = opendir((const char *)("."))))
		return (-1);
	while (i < (nbf + nbd))
	{
		all->ptr = readdir(all->fd2);
		if (all->ptr->d_type == DT_REG)
		{
			if (!(all->regf[a] = (char *)malloc(sizeof(char) * (ft_strlen(all->ptr->d_name)))))
				return (-1);
//			printf("FICHIER %s\n", all->ptr->d_name);
			all->regf[a] = all->ptr->d_name;
			a++;
		}
		else if (all->ptr->d_type ==  DT_DIR)
		{
			if (!(all->dir[b] = (char *)malloc(sizeof(char) * (ft_strlen(all->ptr->d_name)))))
				return (-1);
//			printf("DOSSIER %s\n", all->ptr->d_name);
			all->dir[b] = all->ptr->d_name;
			b++;
		}
		i++;
	}
	closedir(all->fd2);
	return(0);
}*/

int main(int argc, char **argv)
{
	t_all	all;
	int		i;
	int		y;
	int		start;

	start = 0;
	y = 1;
	i = 1;
	ft_init(&all);
	if (argc > 3)
		ft_sort_params(argv, 1);
	int k = -1;
	while (argv[++k])
		printf("ARGV = %s\n", argv[k]);
	if (argc)
	{
		if (argc > 1 && argv[1][0] == '-' && (ft_strlen(argv[1]) > 1))
		{
			while (argv[y])
			{
				if (argv[y][0] == '-')
				{
					if (get_arg(argv[y], &all) == -1)
						return (ft_error(0, &all));
				}
				else
				{
					all.onlyflags = -1;
					break;
				}
				y++;
			}
			if (all.onlyflags < 0)
			{
				start = y - 1;
				y = argc - 1;
				print_bad_files(&all, y, start, argv);
				just_files(&all, argv, argc, start + 1);
				return (0);
			}
			else
			{
				print_ls(&all);
			}
		}
		else if (argc > 1 && (argv[1][0] != '-' || argv[1][1] == '\0'))
		{
			just_files(&all, argv, argc, 1);
			return (0);
		}
		else if (argc == 1)
			print_ls(&all);
		return (0);
	}
	return (0);
}

/*			int k;
k = 0;
while (k < argc - 1)
{
	printf("all.fd[0][%d] = %d\n", k, all.fd[0][k]);
	printf("all.fd[1][%d] = %d\n", k, all.fd[1][k]);
	k++;
}*/

