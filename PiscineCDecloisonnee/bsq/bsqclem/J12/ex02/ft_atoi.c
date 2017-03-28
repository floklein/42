# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_atoi.c~                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/02 21:47:54 by cchaumar          #+#    #+#              #
#    Updated: 2015/11/02 21:48:01 by cchaumar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

int		ft_is_number(int i, char *str)
{
	long	nbr;
	int		j;
	int		out;

	out = 0;
	nbr = 0;
	j = i;
	if (str[i] == '-' || str[i] == '+')
		j = i + 1;
	while (str[j] >= '0' && str[j] <= '9')
	{
		nbr += str[j] - '0';
		nbr *= 10;
		j++;
	}
	if (str[i] == '-')
		nbr = -nbr;
	if (nbr / 2147483647 >= 1)
		out = (nbr / 10) % 4294967296 - 4294967296;
	else
		out = nbr / 10;
	return (out);
}

int		ft_atoi(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' &&
		str[i + 1] >= '0' && str[i + 1] <= '9') || (str[i] == '+' &&
		str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (ft_is_number(i, &str[0]));
		if (str[i] != ' ' && str[i] != 9 && str[i] != 10)
			return (0);
		else
			i++;
	}
	return (0);
}
