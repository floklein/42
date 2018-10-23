/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:35:11 by fklein            #+#    #+#             */
/*   Updated: 2017/03/30 12:14:49 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_conv
{
	char		spec;
	void		*data;
	int			opt_hash;
	int			opt_zero;
	int			opt_minus;
	int			opt_plus;
	int			opt_space;
	int			width_min;
	int			precision;
	int			mod_hh;
	int			mod_h;
	int			mod_l;
	int			mod_ll;
	int			mod_j;
	int			mod_z;
}				t_conv;

int		ft_printf(const char *format, ...);

#endif
