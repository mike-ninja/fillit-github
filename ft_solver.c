/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 05:59:37 by lasalmi           #+#    #+#             */
/*   Updated: 2022/02/07 13:22:34 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_solver(t_board *board, t_tetris *tetri)
{
	int	y;
	int	x;

	y = 0;
	x = tetri->preset_x;
	if (tetri->i == -1)
		return (1);
	while (y < (board->size - tetri->max_y))
	{
		while (x < (board->size - tetri->max_x))
		{
			if (ft_instetri(board, tetri, y, x))
			{
				if (ft_solver(board, (tetri + 1)) == 1)
					return (1);
				else
					ft_term_del(board, tetri);
			}
			x++;
		}
		x = tetri->preset_x;
		y++;
	}
	return (0);
}
