/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:31:26 by flklein           #+#    #+#             */
/*   Updated: 2018/09/05 19:44:31 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	i;

	len_d = 0;
	while (dest[len_d])
		len_d++;
	len_s = 0;
	while (src[len_s])
		len_s++;
	if (size < len_d)
		return (size + len_s);
	i = 0;
	while (len_d + i < size - 1)
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = '\0';
	return (len_d + len_s);
}
/*
int		main(int ac, char **av)
{
	char	*cpy1;

	cpy1 = av[1];
	printf("%d\n", ft_strlcat(cpy1, av[2], atoi(av[3])));
	printf("%s\n", cpy1);
}*/
