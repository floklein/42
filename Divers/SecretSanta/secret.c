/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:41:21 by                   #+#    #+#             */
/*   Updated: 2017/12/28 19:31:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int	gifted(int *guests, int rec)
{
	int	j;

	j = 1;
	while (guests[j])
	{
		if (guests[j] == rec)
			return (1);
		j++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	*guests;
	int	rec;
	
	if (!(guests = (int *)malloc(sizeof(int) * (ac))))
		return (0);
	srand(time(NULL));
	i = 1;
	while (av[i])
	{
		while ((rec = (rand() % ac)) == i || rec == 0 || gifted(guests, rec));
		printf("%10s\toffre à\t%10s\t%d > %d\n", av[i], av[rec], i, rec);
		guests[i] = rec;
	i++;
	}
	free(guests);
	return (0);
};
