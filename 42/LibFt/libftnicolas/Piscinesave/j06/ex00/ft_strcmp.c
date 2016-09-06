/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 00:04:58 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/28 19:15:15 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int c;
	int n1;
	int n2;

	c = 0;
	while (s1[c] != '\0' || s2[c] != '\0')
	{
		if (s1[c] != s2[c])
		{
			n1 = s1[c];
			n2 = s2[c];
			if (n1 > n2 || n1 < n2)
				return (n1 - n2);
		}
		if (s1[c] == s2[c])
			c++;
	}
	return (0);
}
