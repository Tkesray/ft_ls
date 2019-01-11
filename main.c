/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:10:37 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/11 12:26:06 by prastoin         ###   ########.fr       */
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

int		just_files(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (1);
}

void	ft_init(t_all *all)
{
	all->R = 0;
	all->l = 0;
	all->r = 0;
	all->t = 0;
	all->a = 0;
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

int main(int argc, char **argv)
{
	t_all all;
	int		i;

	i = 1;
	ft_init(&all);
	(void)argc;
	if (argv[1][0] != '-')
	{
		if (!(all.fd = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
		while (i < (argc - 1))
		{
			all.fd[i] = open(argv[i], O_RDONLY);
			i++;
		}
		just_files(argv, (argc - 1));
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
