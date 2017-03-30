/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:38:37 by fklein            #+#    #+#             */
/*   Updated: 2017/03/30 17:57:49 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	int	x;
	int	y;
	int	x2;
	int	y2;
	int	x_size;
	int	y_size;
}		t_data;

#endif
