/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:10:37 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/11 12:53:29 by prastoin         ###   ########.fr       */
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

int		just_files(t_all *all, char **argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (all->fd[i] == -1)
		{
			ft_putstr("ls : ");
			ft_putstr(argv[i + 1]);
			ft_putstr(" No such file or directory\n");
		}
		else
			ft_putstr(argv[i + 1]);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_all all;
	int		i;

	i = 1;
	ft_init(&all);
	if (argc == 1)
	{
		ft_ls()
	}
	if (argv[1][0] != '-')
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
		else
			return(0);
	}
	return (0);
}
