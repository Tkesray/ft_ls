/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:53:10 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/11 12:55:00 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
