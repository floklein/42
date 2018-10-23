/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:19:31 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 16:36:35 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	display_errno(char *arg_name)
{
	if (errno == EACCES)
	{
		ft_putstr_stderr("hexdump: ");
		ft_putstr_stderr(arg_name);
		ft_putstr_stderr(": Permission denied\n");
	}
	else if (errno == ENOENT)
	{
		ft_putstr_stderr("hexdump: ");
		ft_putstr_stderr(arg_name);
		ft_putstr_stderr(": No such file or directory\n");
	}
}

void	display_invalid(char invalid_letter)
{
	ft_putstr_stderr("hexdump: illegal option -- ");
	ft_putchar_stderr(invalid_letter);
	ft_putstr_stderr("\n");
}
