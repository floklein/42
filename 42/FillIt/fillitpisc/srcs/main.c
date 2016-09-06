/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsmite <dwight.smite@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 16:58:08 by dsmite            #+#    #+#             */
/*   Updated: 2016/05/01 14:35:04 by dsmite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	free_tetri(t_tetri *tetri, int tetri_nb)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetri_nb)
	{
		j = 0;
		while (j < 4)
		{
			free(tetri[i].pos[j]);
			j++;
		}
		free(tetri[i].pos);
		i++;
	}
	free(tetri);
}

int		main(int argc, char **argv)
{
	t_tetri		*tetri;
	t_square	*sq;
	int			tetri_nb;

	if (argc != 2)
	{
		ft_putstr_stderr("usage: fillit source_file\n");
		return (0);
	}
	if (check_file(argv[1], &tetri_nb))
	{
		ft_putendl("error");
		return (0);
	}
	if ((tetri = stock_tetri(argv[1], tetri_nb)) == NULL)
		return (1);
	sq = (t_square*)malloc(sizeof(t_square));
	solver(tetri, &sq, tetri_nb);
	print_result(tetri, tetri_nb, *sq);
	free(sq);
	free_tetri(tetri, tetri_nb);
	return (0);
}
