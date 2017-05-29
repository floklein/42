/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:07:06 by fklein            #+#    #+#             */
/*   Updated: 2017/05/29 19:11:13 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *str1, const char *str2)
{
	int				c;
	int				n1;
	int				n2;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	c = 0;
	while (s1[c] != '\0' || s2[c] != '\0')
	{
		if (s1[c] != s2[c])
				return (0);
		if (s1[c] == s2[c])
			c++;
	}
	return (1);
}
