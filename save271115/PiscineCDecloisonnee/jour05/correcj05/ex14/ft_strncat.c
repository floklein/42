/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 20:23:22 by fklein            #+#    #+#             */
/*   Updated: 2015/10/27 20:23:24 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, int nb)
{
	int i_dest;
	int i_src;

	i_src = 0;
	i_dest = 0;
	while (dest[i_dest] != '\0')
		i_dest++;
	while (i_dest != ft_strlen(src) + ft_strlen(dest) && i_src != nb)
	{
		dest[i_dest] = src[i_src];
		i_dest++;
		i_src++;
	}
	return (dest);
}
