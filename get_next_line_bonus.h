/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:12:51 by atbicer           #+#    #+#             */
/*   Updated: 2024/07/02 14:52:51 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE > 8000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 8000000
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_and_join(int fd, char *str[]);
char	*ft_line(char **str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
/* Utils */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_free(char **ptr);
char	*ft_strchr(const char *s, int c);
#endif
