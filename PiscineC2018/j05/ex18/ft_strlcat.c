/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 02:11:00 by flklein           #+#    #+#             */
/*   Updated: 2018/09/04 19:58:06 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && j < size - i)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (j < size - i)
		dest[i + j] = '\0';
	k = 0;
	while (src[k])
		k++;
	return (size < i ? size + k : i + k);
}
