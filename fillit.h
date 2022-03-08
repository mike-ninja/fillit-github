/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:40:55 by mbarutel          #+#    #+#             */
/*   Updated: 2022/02/28 11:19:18 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_tetris
{
	int	i;
	int	loc_x;
	int	loc_y;
	int	x[3];
	int	y[3];
	int	preset_x;
	int	max_y;
	int	max_x;
}				t_tetris;

typedef struct s_board
{
	int	size;
	int	**board;
}				t_board;

int		ft_square(int n);
int		ft_validator(int fd, t_tetris *tetri);
int		ft_solver(t_board *board, t_tetris *tetri);
int		ft_instetri(t_board *board, t_tetris *tetri, int y, int x);
void	ft_presets(t_tetris *tetri);
void	ft_printboard(t_board *board);
void	ft_term_del(t_board *board, t_tetris *tetri);
t_board	*ft_createboard(int n);
void	ft_error(void);
#endif