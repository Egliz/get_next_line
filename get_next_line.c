/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:53:44 by emorillo          #+#    #+#             */
/*   Updated: 2025/01/06 20:10:39 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char *remainder = NULL; // Almacena el contenido no procesado
    char		*buffer = NULL;
    char		*newline = NULL;
	char		*temp = NULL;;
    ssize_t		b_read;
	int			i;
	//int			j;
	//j = 0;
    // Verificar condiciones iniciales
    if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= 2147483647) //malloc = int maximo + 1) no se puede hacer.
	 return (NULL);
    // Asignar memoria para el buffer
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (buffer == NULL)
      return (NULL);
	// Leer del archivo
	b_read = 1;
	while ((b_read > 0) && (!ft_strchr(remainder, '\n')))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		remainder = ft_strjoin(remainder, buffer);
	}
	buffer[b_read] = '\0';
	i = 0;
	free(buffer);
	while ((remainder[i] != '\0') && (remainder[i] != '\n'))// while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if(remainder[i] == '\n')
		i++;
	newline = ft_substr(remainder, 0, i);//substr hace el malloc que sirve para newline.
	temp = remainder;
	remainder = ft_substr(remainder, i, ft_strlen(remainder));
	free(temp);
	return(newline);
}

// int main(void)
// {
//     int fd;
//     char *line;

//     // Abre el archivo en modo solo lectura
//     fd = open("archi.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error al abrir el archivo");
//         return (1);
//     }

//     // Llama a get_next_line en un bucle para leer todas las líneas del archivo
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line); // Libera la memoria asignada por get_next_line
//     }

//     // Cierra el archivo
//     close(fd);
//     return (0);
// }

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*pointer;
// 	size_t	tsize;

// 	tsize = nmemb * size;
// 	if (nmemb != 0 && size != 0 && tsize / nmemb != size)
// 		return (NULL);
// 	pointer = malloc(tsize);
// 	if (pointer == NULL)
// 		return (NULL);
// 	ft_bzero(pointer, tsize);
// 	return (pointer);
// }

// //ESTA FUNCION PARA PODER UTILIZAR EL CALLOC
// void	ft_bzero(void *s, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*local_s;

// 	local_s = (unsigned char *)s;
// 	i = 0;
// 	while (i < n)
// 	{
// 		local_s[i] = '\0';
// 		i++;
// 	}
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	int		len;

// 	i = 0;
// 	len = 0;
// 	while (src[len])
// 	{
// 		len++;
// 	}
// 	if (size > 0)
// 	{
// 		while (i < size - 1 && src[i] != '\0')
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (len);
// }
