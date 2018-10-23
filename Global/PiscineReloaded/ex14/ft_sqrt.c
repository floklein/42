/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:15:59 by flklein           #+#    #+#             */
/*   Updated: 2018/10/23 21:58:47 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		root;

	root = 1;
	while (root * root > 0 && root * root < nb)
		root++;
	return (root * root == nb ? root : 0);
}

int		main(int ac, char **av)
{
	printf("%d\n", ft_sqrt(atoi(av[1])));
	return (ac);
}
