/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 00:32:06 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/28 19:19:00 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	int c;
	int result;

	c = 0;
	if (str[c] == '\0')
		return (1);
	while (str[c] != '\0')
	{
		if (str[c] >= 'A' && str[c] <= 'Z')
			result = 1;
		else
			return (0);
		c++;
	}
	return (result);
}
