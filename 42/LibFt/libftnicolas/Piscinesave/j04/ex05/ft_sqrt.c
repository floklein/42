/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 14:28:19 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/27 19:30:39 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int r;

	r = 0;
	while (nb != (r * r) && r < nb)
		r++;
	if (nb == r)
		return (0);
	return (r);
}
