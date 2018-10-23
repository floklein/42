/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 02:02:36 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/28 19:19:42 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int actual_char;
	int last_char;

	actual_char = 0;
	last_char = 0;
	while (dest[last_char] != '\0')
		last_char++;
	while (src[actual_char] != '\0')
	{
		dest[last_char] = src[actual_char];
		last_char++;
		actual_char++;
	}
	dest[last_char] = '\0';
	return (dest);
}
