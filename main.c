/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:46:42 by lasalmi           #+#    #+#             */
/*   Updated: 2022/02/04 11:45:48 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// // This function traverses through the board to find next potential position for placement of the terimino. 

// void	ft_get_next_y_x(int *y_x, t_board *board, int n)
// {
// 	while (y_x[0] < n)
// 	{
// 		while (y_x[1] < n && board->board[y_x[0]][y_x[1]] != -1)
// 			y_x[1]++;
// 		if (y_x[1] < n)
// 			break ;
// 		y_x[0]++;
// 	}
// }

// void ft_solver(t_board *board, t_tetris *tetri, int	n, int qty)
// {
// 	int i;
// 	int y_x[2];

// 	i = 0;
// 	y_x[0] = 0;
// 	y_x[1] = 0;
	
// 	while (i < qty)
// 	{
// 		ft_get_next_y_x(&y_x[0], board, n);
// 		printf("y - %i | x - %i\n", y_x[0], y_x[1]);
// 		tetri[i].loc_y = y_x[0];
// 		tetri[i].loc_x = y_x[1];
// 		if (tetri[i].loc_y >= 0 && tetri[i].loc_x >= 0)
// 			ft_instetri(board, &tetri[i], tetri[i].loc_x, tetri[i].loc_y );
// 		i++;
			
// 	}
	
// 	printf("x %i - y %i\n", y_x[0], y_x[1]);
	
// 	// tetri[i].loc_y = i;
// 	// tetri[i].loc_x = j;
// 	// if (ft_instetri(board, &tetri[i], tetri[i].loc_y, tetri[i].loc_x))

// 	// else
// 	// {
		
// 	// }
// }



int	main(void)
{
	t_board	*boardi;
	t_tetris	test[26];
	int		i;
	int		qty;
	int		n;
	int		fd;

	i = 1;
	fd = open("tetro.txt", O_RDONLY);
	qty = ft_validator(fd, test);
	test[qty].i = -1;
	n = ft_square(qty);
	boardi = ft_createboard(n);
	while (!ft_solver(boardi, &test[0]))
	{
		// printf("This happens\n");
		free(boardi);
		boardi = ft_createboard(n+i);
		i++;
	}
	ft_printboard(boardi);
	printf("\n");
	//Solver function should  be here and it should call the ft_instetri
	// ft_instetri(boardi, &test[0], 0, 0);
	// ft_solver(boardi, &test[0], n, qty);
	//ft_solver(boardi, tetri[0]);
	// while (j < n)
	// {
	// 	while (i < (n - 1))
	// 		printf("|%i|", boardi->board[i++][0]);
	// 	printf("|%i|\n", boardi->board[j][i]);
	// 	i = 0;
	// 	j++;
	// }
	return (0);
}
