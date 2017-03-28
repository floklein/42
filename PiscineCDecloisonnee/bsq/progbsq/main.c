/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 15:00:52 by cchaumar          #+#    #+#             */
/*   Updated: 2015/11/06 18:07:52 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*ft_getline(int fd, t_map *map_info)
{
	char	*s;
	int		n;

	n = map_info->height + 1;
	if ((s = (char *)malloc(sizeof(char) * n)) == NULL)
		return (NULL);
	read(fd, s, n);
	return ((*(s + n - 1) == '\n') ? s : NULL);
}

char	*ft_get_first_line(int fd, t_map *map_info)
{
	t_list	*root;
	t_list	*node;
	int		deep;

	root = NULL;
	deep = 0;
	ft_list_push_back(&root);
	node = root;
	while (read(fd, &(node->c), 1) > 0)
	{
		deep++;
		if (node->c == '\n')
			return ((deep == 1) ? NULL : ft_list_to_tab(root, deep));
		if (map_info)
			if (ft_strf(node->c, map_info->charset))
			{
				ft_destroy(root);
				return (NULL);
			}
		ft_list_push_back(&node);
		node = node->next;
	}
	return (NULL);
}

t_map	*ft_get_map_info(int fd)
{
	char	*charset;
	t_map	*map;
	int		i;

	if ((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	if ((charset = ft_get_first_line(fd, NULL)) == NULL)
		return (NULL);
	i = ft_strlen(charset) - 4;
	map->charset = ft_strdup(charset + i);
	map->charset[3] = '\0';
	charset[i] = '\0';
	map->height = ft_atoi(charset);
	return (map);
}

t_map	*ft_read(char *s, char ***map, int flag)
{
	int		fd;
	int		line;
	t_map	*map_info;

	fd = (flag == 0) ? 0 : open(s, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if ((map_info = ft_get_map_info(fd)) == NULL || !map_info->height)
		return (NULL);
	if (!(*map = (char**)malloc(sizeof(char*) * (1 + map_info->height))))
		return (NULL);
	if (((*map)[0] = ft_get_first_line(fd, map_info)) == NULL)
		return (NULL);
	map_info->width = ft_strlen((*map)[0]);
	line = 0;
	while (++line < map_info->height)
		if (((*map)[line] = ft_getline(fd, map_info)) == NULL)
			return (NULL);
	(*map)[line] = NULL;
	if (flag)
		if (close(fd) == -1)
			return (NULL);
	return (map_info);
}

int		main(int argc, char **argv)
{
	int		i;
	char	**map;
	t_map	*map_info;

	map = NULL;
	i = 0;
	if (argc > 1)
	{
		while (++i < argc)
			if ((map_info = ft_read(argv[i], &map, 1)) == NULL)
				ft_putstr(2, "map error\n");
			else
				ft_run_bsq(map, map_info);
	}
	else
	{
		if ((map_info = ft_read(NULL, &map, 0)) == NULL)
			ft_putstr(2, "map error\n");
		else
			ft_run_bsq(map, map_info);
	}
	return (0);
}
