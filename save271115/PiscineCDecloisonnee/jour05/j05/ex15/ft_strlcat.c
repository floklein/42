/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 20:23:34 by fklein            #+#    #+#             */
/*   Updated: 2015/10/27 20:23:35 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	if (size < ft_strlen(dest))
		return (size + ft_strlen(src));
	if (size >= ft_strlen(dest))
		return (ft_strlen(dest) + ft_strlen(src));
	else
		return (0);
}
