/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:48:03 by mbarutel          #+#    #+#             */
/*   Updated: 2022/02/04 11:56:12 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int    ft_solver(t_board *board, t_tetris *tetri)
{
    int    y;
    int    x;

    y = 0;
    if (tetri->i == -1)
        return (1);
    printf("ft_solver %i\n", tetri->i);
    while (y < board->size)
    {
        x = 0;
        while (x < board->size)
        {
            //printf("tetri Ident - %i\n", tetri->i);
            // printf("{%i, %i}\n", y, x);
            // printf("-- %i\n", tetri->i);
            if (ft_instetri(board, tetri, y, x)) // 4th Tetri doesnt fit,it should
            {
                //printf("ft_insert\n");
                // ft_printboard(board);
                // printf("\n");
                if (ft_solver(board, (tetri + 1)) == 1) // This i dont get what it does when we reach last tetri?
                    return (1);
                else
                {
                    //ft_printboard(board);
                    //printf("\n");
                    //printf("This happens: tetri ident -> %i\n", tetri->i);
                    ft_term_del(board, tetri); // This causes segment fault
                }
            }
            x++;
        }
        y++;
    }
    return (0);
}