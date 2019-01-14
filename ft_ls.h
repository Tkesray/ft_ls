/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:10:55 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/14 11:53:10 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>

typedef struct		s_all
{
	char	badchar;
	char	*str;

	char	**dir;
	char	**regf;
	char	**tab;
	int		*data;

	char	*flag;
	int		R;
	int		l;
	int		a;
	int		r;
	int		t;

	int		*fd[2];
	int		df;
	int		onlyflags;

	DIR		*fd2;
	struct dirent *ptr;
	int		nbrfile;
	int		nbrdir;
}					t_all;

int					create_tab(t_all *all, int nbf, int nbd);
void				printdbchar(char **tab, int i);
void				ft_init(t_all *all);
int					ft_error(int i, t_all *all);
int					just_files(t_all *all, char **argv, int argc, int start);
int					zeroac(t_all *all);
int					data(char **argv, int argc, t_all *all);
int					print_ls(t_all *all);
int					ft_count_files(t_all *all);
int					create_current(t_all *all, int nbf, int nbd);
int					ft_displays(t_all *all, int i);
int					print_bad_files(t_all *all, int y, int start, char **argv);
int					print_good_files(t_all *all, int y, int start, char **argv);

#endif
