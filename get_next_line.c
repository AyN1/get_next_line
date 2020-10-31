/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abicer <abicer@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:00:34 by abicer            #+#    #+#             */
/*   Updated: 2020/02/26 13:45:47 by abicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	else
	{
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
		str = malloc(size);
		if (!str)
			return (NULL);
		while (size--)
			str[size] = 0;
		ft_memcpy(str, s1, ft_strlen(s1));
		ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}

char		*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((char)c == '\0')
		return ((char*)s + ft_strlen(s));
	while (s[i] && s[i] != c)
		++i;
	if (!s[i])
		return (NULL);
	return ((char*)s + i);
}

static	int	get_line(char **str, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	if (!*str)
		return (-1);
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		++i;
	if ((*str)[i] == '\n')
	{
		*line = ft_strsub((*str), 0, i);
		temp = ft_strdup(&(*str)[i + 1]);
		free(*str);
		*str = temp;
		return (1);
	}
	else
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*str[OPEN_MAX] = { NULL };
	char		*temp;
	size_t		ret;

	if (BUFFER_SIZE < 0 || line == NULL || fd < 0 || read(fd, *line, 0) < 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strdup("");
	if (!str[fd])
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (get_line(&str[fd], line));
}
