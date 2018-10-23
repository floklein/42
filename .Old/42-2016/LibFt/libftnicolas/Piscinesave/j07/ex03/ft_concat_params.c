/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:39:43 by nthibaud          #+#    #+#             */
/*   Updated: 2016/01/28 16:39:48 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_params_len(int argc, char **argv)
{
	int len;
	int i;
	int j;

	len = 0;
	i = 0;
	while (i < argc - 1)
	{
		i++;
		j = 0;
		while (argv[i][j] != '\0')
		{
			j++;
			len++;
		}
	}
	return (len);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		c;
	int		len;
	char	*conc_str;

	i = 0;
	c = 0;
	len = ft_params_len(argc, argv);
	if (!(conc_str = (char*)malloc(sizeof(*conc_str) * len + argc)))
		return (NULL);
	while (i < argc - 1)
	{
		i++;
		j = 0;
		while (argv[i][j] != '\0')
			conc_str[c++] = argv[i][j++];
		if (i < argc - 1)
			conc_str[c++] = '\n';
	}
	conc_str[c] = '\0';
	return (conc_str);
}
