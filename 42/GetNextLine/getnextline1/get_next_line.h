/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 18:12:43 by fklein            #+#    #+#             */
/*   Updated: 2017/03/05 21:50:27 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000

typedef struct		stockage
{
	int	*tries;
	char	***files;
}			stockage;

int	get_next_line(const int fd, char **line);
char	*ft_strjoin(const char *str1, const char *str2);
char	**ft_strsplit_mod(const char *s, char c);
void	ft_strclr(char *str);

#endif
