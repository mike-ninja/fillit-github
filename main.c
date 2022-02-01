/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:46:42 by lasalmi           #+#    #+#             */
/*   Updated: 2022/02/01 09:58:50 by lasalmi          ###   ########.fr       */
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
