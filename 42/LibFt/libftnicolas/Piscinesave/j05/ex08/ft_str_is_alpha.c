/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 23:40:38 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/28 19:16:19 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int c;
	int result;

	c = 0;
	result = 0;
	if (str[c] == '\0')
		return (1);
	while (str[c] != '\0')
	{
		if ((str[c] >= 'A' && str[c] <= 'Z') ||
		(str[c] >= 'a' && str[c] <= 'z'))
			result = 1;
		else
			return (0);
		c++;
	}
	return (result);
}
