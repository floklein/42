/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 14:24:50 by cchaumar          #+#    #+#             */
/*   Updated: 2015/11/06 23:14:31 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_fill(t_bsq *node, int i, int j, int size)
{
	node->i = i;
	node->j = j;
	node->size = size;
}

void	ft_color_map(char **map, t_bsq *node, char c)
{
	int	i;
	int j;

	i = node->i - 1;
	while (++i < node->i + node->size)
	{
		j = node->j - 1;
		while (++j < node->j + node->size)
			map[i][j] = c;
	}
}

int		ft_get_bsq(char **map, t_bsq *node, t_map *charset)
{
	int	i;
	int	j;
	int	size;

	size = node->size;
	i = node->i;
	j = node->j + size;
	if (i + size >= charset->height || j >= charset->width)
		return (1);
	while (i <= node->i + size)
		if (map[i++][j] == charset->charset[1])
			return (1);
	j = node->j;
	i = node->i + size;
	while (j <= node->j + size)
		if (map[i][j++] == charset->charset[1])
			return (1);
	node->size++;
	return (1 + ft_get_bsq(map, node, charset));
}

void	ft_cmp_bsq(char **map, t_map *map_info, \
		t_bsq *node, t_bsq *max_node)
{
	node->size = ft_get_bsq(map, node, map_info);
	if (node->size > max_node->size)
		ft_fill(max_node, node->i, node->j, node->size);
}

void	ft_bsq(char **map, t_map *map_info)
{
	t_bsq	*max_node;
	t_bsq	*node;
	int		i;
	int		j;

	i = -1;
	max_node = (t_bsq *)malloc(sizeof(t_bsq));
	node = (t_bsq *)malloc(sizeof(t_bsq));
	if (node && max_node)
	{
		ft_fill(max_node, 0, 0, 0);
		while (++i <= map_info->height - max_node->size)
		{
			j = -1;
			while (++j <= map_info->width - max_node->size)
				if (map[i][j] == map_info->charset[0])
				{
					ft_fill(node, i, j, 1);
					ft_cmp_bsq(map, map_info, node, max_node);
				}
		}
	}
	ft_color_map(map, max_node, map_info->charset[2]);
}
