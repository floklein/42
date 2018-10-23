/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:33:47 by flklein           #+#    #+#             */
/*   Updated: 2018/09/10 17:05:21 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_any(char **tab, int (*f)(char *))
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_putchar(char c)
{write(1, &c, 1);}

int		find_a(char *str)
{
	if (str[0] == 'a')
	{
		ft_putchar('1');
		return (1);
	}
	else
	{
		ft_putchar('0');
		return (0);
	}
}

int		main(void)
{
	char		tab[3][6] = {"salut", "ampoul", "truc"};

	ft_any(tab, &find_a);
}
