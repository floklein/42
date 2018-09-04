/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 20:15:59 by flklein           #+#    #+#             */
/*   Updated: 2018/09/04 19:05:50 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr_16(int nbr)
{
	int		base_n;
	char	*base;

	base_n = 16;
	base = "0123456789abcdef";
	if (nbr >= base_n)
	{
		ft_putnbr_16(nbr / base_n);
		ft_putnbr_16(nbr % base_n);
	}
	else
	{
		ft_putchar(base[nbr]);
	}
}

void	ft_putnstr_np(char *str, int n)
{
	int		i;

	i = 0;
	if (n == -1)
		while (*(str++))
			ft_putchar(*(str - 1));
	else
	{
		while (i < n)
		{
			if (str[i] >= 32 && str[i] <= 126)
				ft_putchar(str[i]);
			else
				ft_putchar('.');
			i++;
		}
	}
}

void	print_0(int add)
{
	if (add < 16)
		ft_putnstr_np("0000000", -1);
	else if (add < 256)
		ft_putnstr_np("000000", -1);
	else if (add < 4096)
		ft_putnstr_np("00000", -1);
	else if (add < 65536)
		ft_putnstr_np("0000", -1);
	else if (add < 1048576)
		ft_putnstr_np("000", -1);
	else if (add < 268435456)
		ft_putnstr_np("00", -1);
	else
		ft_putnstr_np("0", -1);
}

void	print_ascii(char *char_addr, int cur_add, int size, int i)
{
	if (i < size)
	{
		if (char_addr[i] < 16)
			ft_putchar('0');
		ft_putnbr_16(char_addr[i]);
	}
	else
		ft_putnstr_np("  ", -1);
	if (i % 2 && i < cur_add + 15)
		ft_putchar(' ');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*char_addr;
	int		cur_add;
	int		i;

	char_addr = (char *)addr;
	cur_add = 0;
	while (cur_add <= size)
	{
		print_0(cur_add);
		ft_putnbr_16(cur_add);
		ft_putnstr_np(": ", -1);
		i = cur_add;
		while (i < cur_add + 16)
			print_ascii(char_addr, cur_add, size, i++);
		ft_putnstr_np("  ", -1);
		i = cur_add;
		ft_putnstr_np(char_addr + i, cur_add + 16 > size ? size - cur_add : 16);
		ft_putchar('\n');
		cur_add += 16;
	}
	return (addr);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main()
{
	ft_print_memory("", 0);
}
