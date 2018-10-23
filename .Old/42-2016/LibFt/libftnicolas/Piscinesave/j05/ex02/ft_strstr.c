/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 23:49:48 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/28 19:12:26 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int y;
	int l;

	i = 0;
	l = 0;
	while (to_find[l] != '\0')
	{
		l++;
	}
	while (str[i] != '\0')
	{
		y = 0;
		while (to_find[y] == str[i + y])
		{
			if (to_find + y == to_find + l - 1)
				return (str + (y + i) - (l - 1));
			y++;
		}
		i++;
	}
	return (0);
}
