/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 22:50:48 by flklein           #+#    #+#             */
/*   Updated: 2018/08/28 23:14:57 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

char	*ft_strrev(char *str)
{
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(str);
	while (i++ < len / 2 - 1)
		ft_swap(str + i, str + len - 1 - i);
	return (str);
}
