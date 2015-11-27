/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 20:20:47 by fklein            #+#    #+#             */
/*   Updated: 2015/10/27 20:20:50 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int index;

	index = 0;
	while (s1[index] == s2[index]
			&& (s1[index] != '\0' || s2[index] != '\0'))
		index++;
	if (s1[index] == '\0')
		return (-s2[index]);
	if (s2[index] == '\0')
		return (s1[index]);
	return (s1[index] - s2[index]);
}
