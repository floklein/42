/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 17:44:38 by flklein           #+#    #+#             */
/*   Updated: 2018/09/08 17:45:15 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		nmatch(char *s1, char *s2)
{
	if (*s1 != '\0' && *s2 == '*')
	{
		printf("etoile=%s:%s?\n", s1, s2);
		return (nmatch(s1, s2 + 1) + nmatch(s1 + 1, s2));
	}
	if (*s1 == '\0' && *s2 == '\0')
	{
		printf("fin=%s:%s?\n", s1, s2);
		return (1);
	}
	if (*s1 == *s2)
	{
		printf("egal=%s:%s?\n", s1, s2);
		return (nmatch(s1 + 1, s2 + 1));
	}
//	if (*s1 != '\0' && *s2 == '*')
//	{
//		printf("avance2=%s:%s?\n", s1, s2);
//		return (nmatch(s1, s2 + 1));
//	}
	if (*s1 == '\0' && *s2 == '*')
	{
		printf("vide1=%s:%s?\n", s1, s2);
		return (nmatch(s1, s2 + 1));
	}
	return (0);
}

int		main(int ac, char **av)
{
	printf("%d\n", nmatch(av[1], av[2]));
}
