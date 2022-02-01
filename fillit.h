/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:40:55 by mbarutel          #+#    #+#             */
/*   Updated: 2022/02/01 11:50:18 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/inc/libft.h"
//# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_tetris // should contain the coordinates of the first block on the actual board itself
{
    int                 i;
    int                 loc_x;
    int                 loc_y;
    int                 x[3];
    int                 y[3];
}               t_tetris;

typedef struct s_board
{
    int size;
    int **board;
}               t_board;

int     ft_validator(int fd, t_tetris *tetri);
t_board	*ft_createboard(int n);
int	ft_square(int n);
int	ft_instetri(t_board *board, t_tetris *tetri, int x, int y);
#endif