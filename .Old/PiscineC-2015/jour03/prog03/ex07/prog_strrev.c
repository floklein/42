/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_strrev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 23:13:16 by fklein            #+#    #+#             */
/*   Updated: 2015/10/19 23:29:40 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c,1);
}
void	ft_putstr(char *str)
{
		int n;

		n = -1;
		while (*(str + n++))
			ft_putchar(*(str + n));
}

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (*(str + n) != '\0')
		n++;
	return (n);
}

char	*ft_strrev(char *str)
{
	char	temp;
	int		i;
	int		n;

	i = -1;
	n = ft_strlen(str);
	while (i++ < n / 2 - 1)
	{
		temp = *(str + i);
		*(str + i) = *(str + n - 1 - i);
		*(str + n - 1 - i) = temp;
	}
	return (str);
}

int	 main()
{
	char tab[8] = "couscou\0";
	printf("%s", ft_strrev(tab));
}
