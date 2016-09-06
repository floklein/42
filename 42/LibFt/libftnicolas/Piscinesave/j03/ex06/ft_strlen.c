/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 12:24:58 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/22 13:44:16 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int char_count;

	char_count = 0;
	while (str[char_count] != '\0')
	{
		char_count++;
	}
	return (char_count);
}
