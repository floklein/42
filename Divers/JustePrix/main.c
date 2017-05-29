/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:33:57 by fklein            #+#    #+#             */
/*   Updated: 2017/05/29 15:39:13 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int	ask(int players, long number, int count, long **choices)
{
	int	i;

	i = 0;
	while (i < players)
	{
		printf("Choix du joueur %d : ", i + 1);
		scanf("%ld", &((*choices)[i]));
		if ((*choices)[i] < number)
			printf("C'est plus !\n");
		else if ((*choices)[i] > number)
			printf("C'est moins !\n");
		else
		{
			printf("Bravo joueur %d, vous avez trouvé %ld en %d tours !\n", i + 1, number, count);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	int	replay;
	int	niveau;
	long	max;
	int	players;
	long	*choices;
	long	number;
	int	count;

	srand(time(NULL));
	replay = 1;
	while (replay)
	{
		printf("Niveau de jeu (1-10) ? ");
		scanf("%d", &niveau);
		if (niveau >= 1 && niveau <= 10)
			max = pow(10, niveau);
		else
			return (0);
		printf("On cherche un nombre entre 1 et %ld !\n", max);
		printf("Nombre de joueurs (1+) ? ");
		scanf("%d", &players);
		if (!(choices = (long *)malloc(sizeof(long) * players)))
			return (0);
		number = (rand() % max) + 1;
		count = 1;
		while (count < 100)
		{
			if (ask(players, number, count, &choices))
				break;
			count++;
		}
		printf("Rejouer ? 1: Oui 0:Non ");
		scanf("%d", &replay);
	}
	return (0);
}
