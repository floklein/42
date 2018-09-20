/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 00:10:22 by flklein           #+#    #+#             */
/*   Updated: 2018/09/18 00:13:53 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_file_error(char *file)
{
	ft_putstr_err("tail: ");
	ft_putstr_err(file);
	if (errno == EACCES)
		ft_putstr_err(": Permission denied\n");
	else
		ft_putstr_err(": No such file or directory\n");
}

void	ft_offset_error(char *offset)
{
	ft_putstr_err("tail: illegal offset -- ");
	ft_putstr_err(offset);
	ft_putstr_err("\n");
}

void	ft_usage_error(void)
{
	ft_putstr_err("tail: option requires an argument -- c\n\
usage: tail [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]\n");
}
