/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:36:29 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 10:36:31 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_tail(int ac, char **av)
{
	int	bytes_nb;
	int	ret;

	bytes_nb = 0;
	ret = option(&bytes_nb, ac, av);
	if (ret < 0)
		return (-1);
	browse_arg(av, ac, ret, bytes_nb);
	return (0);
}

int	main(int argc, char **argv)
{
	if (ft_tail(argc, argv) == -1)
		return (-1);
	return (0);
}
