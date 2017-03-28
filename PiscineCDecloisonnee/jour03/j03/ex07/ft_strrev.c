/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 23:13:16 by fklein            #+#    #+#             */
/*   Updated: 2015/10/19 23:33:56 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (*(str + n) != '\0')
		n++;
	return (n);
}

char	*ft_strrev(char *str)
{
	char	temp;
	int		i;
	int		n;

	i = -1;
	n = ft_strlen(str);
	while (i++ < n / 2 - 1)
	{
		temp = *(str + i);
		*(str + i) = *(str + n - 1 - i);
		*(str + n - 1 - i) = temp;
	}
	return (str);
}
