/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 12:41:21 by fklein            #+#    #+#             */
/*   Updated: 2015/10/26 19:19:11 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int main()
{
	char tab[90] = "coucu tu veux ma bite?";
	char bat[90] = "coucu tu veux ma bite?";

	printf("%d", match(tab,bat));
}
