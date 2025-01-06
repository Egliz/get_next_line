/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:53:44 by emorillo          #+#    #+#             */
/*   Updated: 2025/01/06 18:38:07 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <unistd.h> // read, close
#include <stdio.h>
#include <fcntl.h> // open
#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char *remainder = NULL; // Almacena el contenido no procesado
    char		*buffer = NULL;
    char		*newline = NULL;
   // char		*temp = NULL;;
   // char		*ret;
    ssize_t		b_read;
	int			i;
	int			j;
	int			k;
	size_t		l;
	j = 0;
	k = 0;

	//(void)ret;
    // Verificar condiciones iniciales
    if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= 2147483647) //malloc = int maximo + 1) no se puede hacer.
	 return (NULL);
    // Asignar memoria para el buffer
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (buffer == NULL)
      return (NULL);
	// Leer del archivo
	b_read = read(fd, buffer, BUFFER_SIZE);
	if (b_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	//l = ft_strlen(buffer);
	if(remainder == NULL)
	{
		l = ft_strlen(buffer);
		remainder =  ft_calloc(l, sizeof(char)); //con el tamano de buffer ft_strdup(buffer);//revisar si tambien se puede hacer: remainder = ft_strdup(buffer);
	}
	while (ft_strchr(buffer, '\n')) //k  < b_read && buffer[k] != '\n'))
	{	
		remainder = ft_strjoin(remainder, buffer);
		/*b_read = */ read(fd, buffer, BUFFER_SIZE);
		printf("hola");
	}
	free(buffer); //despues de concatenarlo con remainder
    remainder[b_read] = '\0';
	i = 0;
	while (remainder[i] != '\0' && remainder[i] != '\n')// while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	newline = malloc(i + 2);//poner que necesito un espacio para chars.
	if (newline == NULL)
		return (NULL);
	ft_strlcpy(newline, remainder, i + 2); //copia hasta \n o \0
	newline[i] = '\n';
	newline[i + 1] = '\0';
	return(newline);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	char			*str;

	str = (char *)s;
	ch = (unsigned char)c;
	while (*str != ch && *str != '\0')
		str++;
	if ((*str == ch) || (ch == '\0'))
		return (str);
	else
		return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	size_t	tsize;

	tsize = nmemb * size;
	if (nmemb != 0 && size != 0 && tsize / nmemb != size)
		return (NULL);
	pointer = malloc(tsize);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, tsize);
	return (pointer);
}

//ESTA FUNCION PARA PODER UTILIZAR EL CALLOC
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*local_s;

	local_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		local_s[i] = '\0';
		i++;
	}
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
if (*s1 == 0) 
	{
	//	free(s1);
		s1 = malloc(1);
		if(s1 == NULL)
			return (NULL);
		//s1 = '\0';
	}
	//if ((s1 == NULL) || (s2 == NULL))
	//	return (NULL);
	new = malloc (ft_strlen(&s1[i]) + ft_strlen(&s2[j]) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	dest = malloc (sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	//if (!s)
	//	return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	while (src[len])
	{
		len++;
	}
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

int main(void)
{
    int fd;
    char *line;

    // Abre el archivo en modo solo lectura
    fd = open("archi.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    // Llama a get_next_line en un bucle para leer todas las líneas del archivo
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Libera la memoria asignada por get_next_line
    }

    // Cierra el archivo
    close(fd);
    return (0);
}
