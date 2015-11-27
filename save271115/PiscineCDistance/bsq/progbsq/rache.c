/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rache.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:58:24 by fklein            #+#    #+#             */
/*   Updated: 2015/11/07 18:01:53 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_test(int i, int j, char **map, t_map *map_info)
{
	return (!(j == map_info->width - max_node->size
			&& map[i][j] == map_info->charset[1])
			&& map[i][j] == map_info->charset[0]);
}
