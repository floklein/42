/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 20:22:08 by fklein            #+#    #+#             */
/*   Updated: 2015/10/27 20:22:09 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z'))
	{
		i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}
