/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 11:54:30 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/28 19:20:54 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int actual_char;
	int last_char;

	actual_char = 0;
	last_char = 0;
	while (dest[last_char] != '\0')
		last_char++;
	while (src[actual_char] != '\0' && actual_char < nb)
	{
		dest[last_char] = src[actual_char];
		last_char++;
		actual_char++;
	}
	dest[last_char] = '\0';
	return (dest);
}
