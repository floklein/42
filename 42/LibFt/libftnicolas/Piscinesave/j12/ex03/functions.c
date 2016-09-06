/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:25:30 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 12:26:54 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_stderr(char c)
{
	write(2, &c, 1);
}

void	ft_putstr(char *str)
{
	int		count;

	count = 0;
	while (*(str + count) != '\0')
	{
		ft_putchar(*(str + count));
		count++;
	}
}

void	ft_putstr_stderr(char *str)
{
	int		count;

	count = 0;
	while (str[count])
	{
		ft_putchar_stderr(str[count]);
		count++;
	}
}

int		ft_strlen(char *str)
{
	int		char_count;

	char_count = 0;
	while (str[char_count] != '\0')
		char_count++;
	return (char_count);
}
