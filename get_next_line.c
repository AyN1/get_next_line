/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:11:22 by atbicer           #+#    #+#             */
/*   Updated: 2024/06/30 18:05:17 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	join = malloc(total_len + 1);
	if (!join)
		return (NULL);
	ft_strlcpy(join, (char *)s1, s1_len + 1);
	ft_strlcpy(join + s1_len, (char *)s2, total_len + 1);
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
//
/* 77 envoi l'adresse de la string a partir du '\n' */

char	*ft_line(char **str)
{
	char	*line;
	char	*temp;
	size_t	i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		++i;
	if ((*str)[i] == '\n')
	{
		line = ft_substr(*str, 0, i + 1);
		temp = ft_strdup(&(*str)[i + 1]);
		free(*str);
		*str = temp;
	}
	else if ((*str)[i] == '\0' && i > 0)
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	else
		line = NULL;
	return (line);
}

char	*read_and_join(int fd, char *str)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	size_t	ret;

	if (read(fd, buf, 0) < 0)
		return (ft_free(&str));
	while (1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		buf[ret] = 0;
		temp = ft_strjoin(str, buf);
		if (!temp)
			return (NULL);
		free(str);
		str = temp;
		if (ft_strchr(str, '\n') || ret <= 0)
			break ;
	}
	return (str);
}

/* 117 Handle the case where there's nothing more to read */

char	*get_next_line(int fd)
{
	static char	*str = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, " ", 0) < 0)
		return (ft_free(&str));
	if (!str)
		str = ft_strdup("");
	if (!str)
		return (NULL);
	str = read_and_join(fd, str);
	if (!str)
		return (NULL);
	if (str[0] == '\0')
		return (ft_free(&str));
	return (ft_line(&str));
}
