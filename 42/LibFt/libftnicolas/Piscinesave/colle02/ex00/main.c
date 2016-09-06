/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 11:38:52 by nthibaud          #+#    #+#             */
/*   Updated: 2015/11/01 22:38:55 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	colle(int x, int y);

int		main(int argc, char **argv)
{
	int i;
	int j;
	int arg1;
	int arg2;
	
	i = 0;
	arg1 = 0;
	arg2 = 0;
	if (argc >= 2 && argc <= 3)
	{
		while (i < argc - 1)
		{
			j = 0;
			i++;
			while (argv[i][j] != '\0')
			{
				if (argv[i][j] < 48 || argv[i][j] > 57)
					return (0);
				if (i == 1)
					arg1 = arg1 * 10 + argv[i][j] - 48;	
				if (i == 2)
					arg2 = arg2 * 10 + argv[i][j] - 48;
				j++;
			}
		}
		
	}
	colle(arg1, arg2);
	return (0);
}
