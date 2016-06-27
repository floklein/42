/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 18:49:59 by cchaumar          #+#    #+#             */
/*   Updated: 2016/01/23 19:21:20 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list	*node;

	if ((node = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	node->content = (content == NULL) ? NULL :
		ft_memcpy(ft_memalloc(content_size), content, content_size);
	node->content_size = (content == NULL) ? 0 : content_size;
	node->next = NULL;
	return (node);
}
