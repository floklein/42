/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 00:13:45 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/28 19:17:20 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	int c;
	int result;

	c = 0;
	result = 0;
	if (str[c] == '\0')
		return (1);
	while (str[c] != '\0')
	{
		if (str[c] >= '0' && str[c] <= '9')
			result = 1;
		else
			return (0);
		c++;
	}
	return (result);
}
