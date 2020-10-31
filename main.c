/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abicer <abicer@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:12:13 by abicer            #+#    #+#             */
/*   Updated: 2020/03/03 19:09:31 by abicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define NBR_EXEC 600

int	main(int argc, char **argv)
{
	int		fd;
	char	*ligne;
	int		ret;
	int		i = 0;

	ligne = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc == 1 || argc > 2)
	{
		printf("usage: ./a.out text.txt\n");
		return (0);
	}

	while (ret >= -1 && i < NBR_EXEC)
	{
		ret = get_next_line(fd, &ligne);
		printf("[%d] ", ret);
		if (ret < 0)
			break ;
		printf("%s\n", ligne);
		free(ligne);
		ligne = NULL;
		if (ret == 0)
			break ;
		// ++i; // NBR_EXEC
	}
	system("leaks -nocontext a.out | grep -A5 \"malloced\"");
	return (0);
}
