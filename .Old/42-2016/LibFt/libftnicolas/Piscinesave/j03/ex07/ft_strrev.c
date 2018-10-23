/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 13:57:57 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/27 14:04:22 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int char_count;

	char_count = 0;
	while (*(str + char_count) != '\0')
	{
		char_count++;
	}
	return (char_count);
}

char	*ft_strrev(char *str)
{
	int		count_char;
	int		last_char;
	char	tmp_char;

	count_char = 0;
	last_char = ft_strlen(str);
	while (*(str + count_char) != *(str + last_char / 2))
	{
		tmp_char = *(str + count_char);
		*(str + count_char) = *(str + (last_char - count_char - 1));
		*(str + (last_char - count_char - 1)) = tmp_char;
		count_char++;
	}
	return (str);
}
