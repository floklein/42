/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 17:14:04 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/28 19:10:56 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_copy(char *str1, char *str2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int j;

	j = 0;
	while (src[j])
		j++;
	if (n <= j)
		ft_copy(dest, src, n);
	else
	{
		ft_copy(dest, src, n);
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (dest);
}
