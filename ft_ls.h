/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:10:55 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/11 12:54:58 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_data
{
	char	badchar;
	char	*str;
	char	*flag;
	int		R;
	int		l;
	int		a;
	int		r;
	int		t;
	int		*fd;
}					t_all;

void				ft_init(t_all *all);
int					ft_error(int i, t_all *all);
int					just_files(t_all *all, char **argv, int argc);

#endif
