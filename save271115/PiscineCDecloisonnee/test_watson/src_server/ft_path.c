/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 17:31:56 by nsavry            #+#    #+#             */
/*   Updated: 2015/08/26 22:09:54 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void	ft_protect_pwd(t_socket *so)
{
	int		i;
	char	*tmp;
	int		test;

	i = 0;
	while (so->tab[++i])
	{	
		if (so->tab[i][0] != '-')
		{
			test = 0;
			if (so->tab[i][ft_strlen(so->tab[i]) - 1] != '/')
			{
				tmp = so->tab[i];
				so->tab[i] = ft_strjoin(so->tab[i], "/");
				test = 1;
				free(tmp);
			}
			tmp = so->tab[i];
			if (so->tab[i][0]  == '/')
				so->tab[i] = ft_strjoin(so->home, so->tab[i]);
			else
				so->tab[i] = ft_strjoin(so->pwd, so->tab[i]);
			free(tmp);
			ft_remove_double(so, i);
			if (ft_strlen(so->home) > ft_strlen(so->tab[i]))
			{
				free(so->tab[i]);
				so->tab[i] = ft_strdup(so->home);
			}
			if (test == 1)
				so->tab[i][ft_strlen(so->tab[i]) - 1] = 0;
		}
	}
}



void	ft_remove_double(t_socket *so, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	while (so->tab[i][j + 1])
	{
		if (so->tab[i][j] == '/')
		{
			if (so->tab[i][j + 1] == '/')
			{
				tmp = so->tab[i];
				so->tab[i] = ft_strsubin(so->tab[i], j, j + 1);
				free(tmp);
				j = 0;
			}
		}
		j++;
	}
	ft_remove_current(so, i);
}

void	ft_remove_current(t_socket *so, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	while (so->tab[i][j + 2])
	{
		if (so->tab[i][j] == '/')
		{
			if (so->tab[i][j + 1] == '.')
			{
				if (so->tab[i][j + 2] == '/')
				{
					tmp = so->tab[i];
					so->tab[i] = ft_strsubin(so->tab[i], j, j + 2);
					free(tmp);
					j = 0;
				}
			}
		}
		j++;
	}
	ft_remove_before(so, i);
}

void	ft_remove_before(t_socket *so, int i)
{
	int		j;
	unsigned int		k;
	char	*tmp;

	j = 0;
	while (so->tab[i][j] && so->tab[i][j + 3] && j >= 0)
	{
		if (so->tab[i][j] == '/' && so->tab[i][j + 1] == '.')
		{
			if (so->tab[i][j + 2] == '.' && so->tab[i][j + 3] == '/')
			{
				tmp = so->tab[i];
				k = ft_search_slash(so->tab[i], j - 1);
				if (k + 1 < ft_strlen(so->home))
					so->tab[i] = ft_strsubin(so->tab[i], j, j + 3);
				else
					so->tab[i] = ft_strsubin(so->tab[i], k, j + 3);
				free(tmp);
				j = 0;
			}
		}
		j++;
	}
}
