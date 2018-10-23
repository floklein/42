/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 21:03:07 by fklein            #+#    #+#             */
/*   Updated: 2015/10/22 21:31:10 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot42(char *str)
{
	int index;

	index = 0;
	while (*(str + index))
	{
		if ((*(str + index) >= 'a' && *(str + index) <= 'z'))
		{
			*(str + index) -= 'a';
			*(str + index) = (*(str + index) + 10) % 26;
			*(str + index) += 'a';
		}
		if ((*(str + index) >= 'A' && *(str + index) <= 'Z'))
		{
			*(str + index) -= 'A';
			*(str + index) = (*(str + index) + 10) % 26;
			*(str + index) += 'A';
		}
		index++;
	}
	return (str);
}
