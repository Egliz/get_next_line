/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:51:23 by emorillo          #+#    #+#             */
/*   Updated: 2025/01/06 20:06:00 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <unistd.h> // read, close
#include <stdio.h>
#include <fcntl.h> // open
// se usa el valor que se prefiera, si en la evalucion no se proporciona ningun valor, se usa este como predeterminado
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
