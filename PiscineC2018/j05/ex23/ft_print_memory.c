/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 20:15:59 by flklein           #+#    #+#             */
/*   Updated: 2018/09/03 22:43:41 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr_16(int nbr, int size)
{
	int		base_n;
	char	*base;

	base_n = 16;
	base = "0123456789abcdef";
	if (nbr >= base_n)
	{
		ft_putnbr_16(nbr / base_n, size - 1);
		ft_putnbr_16(nbr % base_n, 0);
	}
	else
	{
		ft_putchar(base[nbr]);
	}
}

void	*ft_print_memory(char *addr, unsigned int size)
{
	int		cur_add;
	int		i;

	while (cur_add <= size && addr[cur_add])
	{
		ft_putnbr_16(cur_add, 8);
		ft_putchar(':');
		ft_putchar('\t');
		i = cur_add;
		while (i < cur_add + 16 && addr[i])
		{
			ft_putnbr_16(addr[i], 2);
			if (addr[i + 1])
				ft_putnbr_16(addr[i + 1], 2);
			ft_putchar('\t');
			i += 2;
		}
		ft_putchar('\t');
		i = cur_add;
		while (i < cur_add + 16 && addr[i])
		{
			if (addr[i] >= 32 && addr[i] <= 126)
				ft_putchar(addr[i]);
			else
				ft_putchar('.');
			i++;
		}
		ft_putchar('\n');
		cur_add += 16;
	}
	return (addr);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	ft_print_memory(av[1], atoi(av[2]));
}
