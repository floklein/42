/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 11:26:06 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/25 12:40:02 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		match(char *s1, char *s2)
{
	if (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (1);
		return (match(s1 + 1, s2 + 1));
	}
	if (*s2 == '*')
	{
		while (*(s2 + 1) != *(s1 + 1))
		{
			if (*(s1 + 1) == '\0')
				return (0);
			s1++;
		}
		return (match(s1 + 1, s2 + 1));
	}
	return (0);
}

int		main(void)
{
	char tab[] = "coucou tu veux voir ma*?";
	char bat[] = "coucou tu veux voir ma bite ?";

	printf("%d\n",match(bat, tab));
	return (0);
}
