/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:25:50 by mbarutel          #+#    #+#             */
/*   Updated: 2022/02/01 10:45:15 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	ft_term_del(t_board *board, t_tetris tetri)
{
	int	i;
	int	y;
	int	x;

	i = 2;
	while (i >= 0)
	{
		y = tetri.y[i];
		x = tetri.x[i];
		board->board[tetri.loc_y + y][tetri.loc_x + x] = -1;
		i--;
	}
	tetri.loc_x = -1;
	tetri.loc_y = -1;
}
