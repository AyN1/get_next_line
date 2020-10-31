/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abicer <abicer@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:12:13 by abicer            #+#    #+#             */
/*   Updated: 2020/03/03 19:09:35 by abicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#define NBR_EXEC 600

int	main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		i = 0;
	char	*ligne = NULL;
	int		ret = 1;
	int		ret2 = 1;

	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	if (argc != 3)
	{
		printf("usage: ./a.out text.txt text2.txt\n");
		return (0);
	}
	while ((ret || ret2) && i < NBR_EXEC)
	{
		if (ret)
		{
			ret = get_next_line(fd, &ligne);
			printf("ret1: [%d] ", ret);
			if (ret < 0)
				break ;
			printf("%s\n", ligne);
			if (ret < 0)
				ret = 0;
			free(ligne);
			ligne = NULL;
		}
		if (ret2)
		{
			ret2 = get_next_line(fd2, &ligne);
			printf("ret2: [%d] ", ret2);
			if (ret2 < 0)
				break ;
			printf("%s\n", ligne);
			if (ret2 < 0)
				ret2 = 0;
			free(ligne);
			ligne = NULL;
		}
		++i; // NBR_EXEC
	}
	system("leaks -nocontext a.out | grep -A5 \"malloced\"");
	return (0);
}
