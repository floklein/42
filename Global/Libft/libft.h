/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:22:08 by flklein           #+#    #+#             */
/*   Updated: 2018/11/08 12:45:49 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strrchr(const char *s, int c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *src);
unsigned int	ft_strlcat(char *dest, const char *src, size_t size);
int				ft_strlen(char *str);
char			*ft_strncat(char *dest, const char *src, size_t nb);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strchr(const char *s, int c);

#endif
