/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abicer <abicer@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:33:13 by abicer            #+#    #+#             */
/*   Updated: 2020/02/04 17:35:05 by abicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (s)
	{
		i = 0;
		str = malloc(len + 1);
		if (!str)
			return (NULL);
		while (s[start] && i < len)
		{
			str[i] = s[start];
			++i;
			++start;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s1_cpy;

	i = 0;
	s1_cpy = (char*)malloc(ft_strlen(s1) + 1);
	if (s1_cpy == NULL)
		return (NULL);
	while (s1[i])
	{
		s1_cpy[i] = s1[i];
		i++;
	}
	s1_cpy[i] = '\0';
	return (s1_cpy);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ptr_dst;
	const char	*ptr_src;

	i = 0;
	ptr_dst = (char	*)dst;
	ptr_src = (const char *)src;
	if (dst || src)
	{
		while (i < n)
		{
			ptr_dst[i] = ptr_src[i];
			++i;
		}
		return (dst);
	}
	return (0);
}

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i])
		i++;
	while (*s2)
	{
		s1[i] = *s2;
		i++;
		s2++;
	}
	s1[i] = '\0';
	return (s1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
