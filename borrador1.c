/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borrador1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:53:44 by emorillo          #+#    #+#             */
/*   Updated: 2025/01/05 15:33:21 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // malloc, free
#include <unistd.h> // read, close
#include <stdio.h>
#include <fcntl.h> // open
#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char *remainder = NULL; // Almacena el contenido no procesado
    char		*buffer;
    char		*newline = NULL;
    char		*temp = NULL;;
    char		*ret;
    ssize_t		b_read;
	int			i;
	int			j;
	j = 0; //ponerla donde toque
	int			k;
	k = 0;
	(void)ret;
    // Verificar condiciones iniciales
  // si el buffer size es igual a 2147483647 el malloc + 1 no se puede hacer, meterlo en el condicional
    if (BUFFER_SIZE <= 0 || fd < 0)
       { return (NULL);}

    // Asignar memoria para el buffer
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (buffer == NULL)
      {  return (NULL);}

		// Leer del archivo
	b_read = read(fd, buffer, BUFFER_SIZE);
	if (b_read <= 0)
	{
		free(buffer);
		return (NULL);
	}

	//b_read = read(fd, buffer, BUFFER_SIZE);
	if (b_read > 0) {
    buffer[b_read] = '\0';
    ret = ft_strjoin(remainder, buffer);
    free(remainder);
    remainder = ret;
}

	
	if(remainder == NULL)
	{
		remainder = ft_strdup("");//revisar si tambien se puede hacer: remainder = ft_strdup(buffer);
	}
		while ((k < b_read && buffer[k] != '\n' && buffer[k] != '\0'))
		{
			
			remainder = ft_strjoin(remainder, buffer);
			b_read = read(fd, buffer, BUFFER_SIZE);
			remainder = ft_strjoin(remainder, buffer);
			k++;
				//if(b_read < BUFFER_SIZE)
				//{
					//b_read = read(fd, buffer, BUFFER_SIZE);
				//	break;
				//}
		}
		//break;


    remainder[b_read] = '\0';

	 // Concatenar buffer a remainder
	//if(remainder == NULL)
	//{
	//	remainder = ft_strdup(buffer);
	//}
	//else //plantearme el else
	//{
		//ft_strjoin(remainder, buffer);
		temp = malloc(ft_strlen(remainder) + ft_strlen(buffer) + 1);//temp para conactenar con remainder
		if (temp == NULL)//verificar la reserva de memoria
		{
			free(temp);//averiguar pq se libera temp primero si desde un prncipio buffer ya tiene su memoria asignada
			free(buffer);
			free(remainder);
			return (NULL);
		}
		//puedo crear una funcion con esto, seria parecido a un strjoin, pero no exactamente
		i = ft_strlen(remainder);
		while(*remainder && buffer[j] != '\0')
		{
			remainder[i] = buffer[j];
			i++;
			j++;
		}
		//remainder[i] = '\0';
		free(temp);
		temp = ft_strdup(remainder);
		temp [i] = '\0';
		//free(remainder);
 //duplico todo
		//free(remainder);/? creo que no ya que esta variable es la estatica y la necesto para ir guardando todo ahi/??
		
	//}/*
    // Encontrar el fin de línea
	//usar temp si no entra en el else
   	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
	{
		i++;
	}
	//temp[i] = '\n';
	newline = malloc(i + 2);//poner qe necesito un espacio para chars.
	if (newline == NULL)
	{
		return (NULL);
 	}
	ft_strlcpy(newline, temp, i + 2); //copia hasta \n o \0
	//temp[i] = '\n';
	//newline[i] = '\0';
	//i = 0;
	//while (/*i >=0 &&*/ temp[i] != '\0') //while (temp[i] != '\0' && temp[i] != '\n')  //while (/*i >=0 &&*/ temp[i] != '\0')
	//{
	//	newline[i] = temp[i];
	//	i++;
	//}
	//temp[i] = '\n';
	newline[i] = '\0';
	//newline[i] = '\0';/????
	//free(temp);*/
	//free(remainder);
	//free(buffer);
    // Asignar memoria para la línea a retornar

    // Copiar el contenido de remainder a ret

    // Actualizar remainder para la próxima llamada

    // Liberar memoria y retornar la línea
    //free(buffer);
    //return ("holaaa");
	return(newline);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
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
