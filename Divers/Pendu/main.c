/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:47:30 by fklein            #+#    #+#             */
/*   Updated: 2017/05/29 19:28:47 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int	ask(char *word, char **search, int len)
{
	char	letter;
	int	i;
	int	in_it;

	printf("\nMot : %s\nVous proposez ? ", *search);
	while (getchar() != '\n');
	letter = getchar();
	i = 0;
	in_it = 0;
	while (i < len)
	{
		if (word[i] == letter)
		{
			(*search)[i] = letter;
			in_it = 1;
		}
		i++;
	}
	return (in_it);
}

int	main(void)
{
	char	*entry;
	char	*word;
	char	*search;
	int	len;
	int	level;
	int	i;
	int	pendu;

	srand(time(NULL));
	printf("Niveau (1-10) ? ");
	scanf("%d", &level);
	if (level < 1 || level > 10)
		return (0);
	printf("Mot à deviner ? ");
	scanf("%s", entry);
	len = ft_strlen(entry);
	if (!(word = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (!(search = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (i++ < 30)
		printf("\n");
	word[0] = entry[0];
	search[0] = word[0];
	i = 1;
	while (i < len)
	{
		word[i] = entry[i];
		if (!(rand() % (level / 2 + 2)))
			search[i] = word[i];
		else
			search[i] = '_';
		i++;
	}
	pendu = 14 - level;
	while (pendu)
	{
		if (!ask(word, &search, len))
			printf("Oups ! Encore %d essais...\n", pendu-- - 1);
		if (ft_strcmp(word, search))
		{
			printf("\nGagné !\n");
			return (0);
		}
	}
	printf("\nPerdu... Le mot était \"%s\"\n", word);
	return (0);
}
