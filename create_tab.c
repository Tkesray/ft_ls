/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 10:49:59 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/14 11:07:23 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		create_tab(t_all *all, int nbf, int nbd)
{
	int	i;

	i = 0;
	if (!(all->tab = (char **)malloc(sizeof(char *) * (nbf + nbd + 1))))
		return (-1);
	all->tab[nbd + nbf] = NULL;
	if (!(all->data = (int *)malloc(sizeof(int) * (nbf + nbd))))
		return (-1);
	if (!(all->fd2 = opendir((const char *)("."))))
		return (-1);
	while (i < (nbf + nbd))
	{
		all->ptr = readdir(all->fd2);
		if (all->ptr->d_type == DT_REG)
		{
			all->data[i] = 0;
		}
		else if (all->ptr->d_type ==  DT_DIR)
		{
			all->data[i] = 1;
		}
		if (!(all->tab[i] = (char *)malloc(sizeof(char) * (ft_strlen(all->ptr->d_name)))))
			return (-1);
		all->tab[i] = all->ptr->d_name;
		i++;
	}
	closedir(all->fd2);
	return(0);
}
