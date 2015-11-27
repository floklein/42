/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 20:23:44 by fklein            #+#    #+#             */
/*   Updated: 2015/10/27 20:23:45 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*dest_adress;
	const char		*src_adress;
	unsigned int	size_copy;

	dest_adress = dest;
	src_adress = src;
	size_copy = size;
	if (size_copy != 0 && --size_copy != 0)
	{
		if ((*dest_adress++ = *src_adress++) == 0)
			return (0);
	}
	while (size_copy != 0)
		size_copy--;
	if (size_copy == 0)
	{
		if (size != 0)
			*dest_adress = '\0';
		while (*src_adress++)
			;
	}
	return (src_adress - src - 1);
}
