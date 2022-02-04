/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:16:23 by mbarutel          #+#    #+#             */
/*   Updated: 2022/02/04 11:16:44 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_printboard(t_board *boardi)
{
    int y;
    int x;
    
    y = 0;
    while (y <= (boardi->size - 1))
	{
        x = 0;
		while (x <= (boardi->size - 1))
        {
            if (boardi->board[y][x] >= 0)
                printf("|%c|", (boardi->board[y][x] + 65));
            else
                printf("|%c|", '.');
            x++;
        }
            
		printf("\n");
        y++;
    }
}