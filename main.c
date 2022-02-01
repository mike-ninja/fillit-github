/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:46:42 by lasalmi           #+#    #+#             */
/*   Updated: 2022/02/01 12:03:23 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(void)
{
	t_board	*boardi;
	t_tetris	test[26];
	int		i;
	int		n;
	int		j;
	int		fd;

	fd = open("tetro.txt", O_RDONLY);
	j = 0;
	n = ft_square(ft_validator(fd, test));
	i = 0;
	printf("n - %i\n", n);
	boardi = ft_createboard(n);
	ft_instetri(boardi, &test[0], 0, 0);
	while (j < n)
	{
		while (i < (n - 1))
			printf("|%i|", boardi->board[i++][0]);
		printf("|%i|\n", boardi->board[j][i]);
		i = 0;
		j++;
	}
}
