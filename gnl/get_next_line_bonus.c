/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:56:42 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/03 15:50:27 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_negative(char **x, char **line)
{
	if (ft_strchr(*x, '\0'))
	{
		*line = ft_strdup(*x);
		free(*x);
		*x = NULL;
		return (0);
	}
	return (0);
}

int	ft_nbytesnegativo(ssize_t *nbytes, char **x)
{
	if (*nbytes < 0)
	{
		if (*x != NULL)
		{
			free(*x);
			*x = NULL;
		}
		return (-1);
	}
	return (0);
}

int	ft_aux(ssize_t nbytes, char **x, char **line)
{
	char	*tmp;
	char	*tmp2;

	if (!nbytes && !*x)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ft_nbytesnegativo(&nbytes, &*x))
		return (-1);
	tmp = ft_strchr(*x, '\n');
	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strdup(*x);
		tmp2 = ft_strdup(tmp + 1);
		free(*x);
		*x = tmp2;
		return (1);
	}
	else if (ft_negative(&*x, &*line))
		return (0);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*x[4096];
	ssize_t		nbytes;
	char		*tmp;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nbytes = read(fd, buff, BUFFER_SIZE);
	while (nbytes)
	{
		buff[nbytes] = '\0';
		if (!x[fd])
			x[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(x[fd], buff);
			free(x[fd]);
			x[fd] = tmp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
		nbytes = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	buff = NULL;
	return (ft_aux(nbytes, &x[fd], &*line));
}
