/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_stock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 15:30:12 by nthibaud          #+#    #+#             */
/*   Updated: 2015/11/01 23:00:02 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_lenght(char *str);
int		ft_height(char *str);
int		ft_display_tab(char *mega_tab);

int		main(void)
{
	int i;
	int ret;
	int buf;
	char mega_tab[50000];

	i = 0;
	ret = 1;
	while (read(0, &buf, 1))
	{
		mega_tab[i] = buf;
		i++;
	}
	ft_display_tab(mega_tab);
	return(0);	
}
