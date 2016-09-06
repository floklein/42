/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 23:06:42 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/28 18:52:44 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lowercase(int c, char *str)
{
	if ((str[c - 1] >= 32 && str[c - 1] <= 64) ||
	(str[c - 1] >= 91 && str[c - 1] <= 96) ||
	(str[c - 1] >= 123 && str[c - 1] <= 126))
		str[c] = str[c] - 32;
}

void	ft_uppercase(int c, char *str)
{
	if ((str[c - 1] >= 65 && str[c - 1] <= 90) ||
	(str[c - 1] >= 48 && str[c - 1] <= 57) ||
	(str[c - 1] >= 97 && str[c - 1] <= 122))
		str[c] = str[c] + 32;
}

char	*ft_strcapitalize(char *str)
{
	int c;

	c = 0;
	if (str[c] >= 'a' && str[c] <= 'z')
		str[c] = str[c] - 32;
	c++;
	while (str[c] != '\0')
	{
		if (str[c] >= 32 && str[c] <= 126)
		{
			if (str[c] >= 'a' && str[c] <= 'z')
				ft_lowercase(c, str);
			if (str[c] >= 'A' && str[c] <= 'Z')
				ft_uppercase(c, str);
		}
		c++;
	}
	return (str);
}
