/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 18:03:53 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/05 18:03:54 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H

# define VISUALIZER_H

# include "push_swap.h"

# define HEIGHT		1000
# define WIDTH		2000

# define GREY_1		0x333333
# define GREY_2		0x222222
# define YELLOW		0xF0D347

# define REVERSE		"\e[7m"
# define RESET_REVERSE	"\e[27m"

typedef struct		s_visualizer
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_visualizer;

typedef struct		s_push_swap
{
	int				width_coeff;
	int				height_coeff;
	t_stack			*a_stack;
	t_stack			*b_stack;
}					t_push_swap;

typedef struct		s_rectangle
{
	int				x_start;
	int				x_end;
	int				y_start;
	int				y_end;
}					t_rectangle;

/*
** Init
*/

t_push_swap			*init_push_swap(int argc,
						char **argv);
t_visualizer		*init_visualizer(void);

/*
** Draw
*/

void				draw(t_push_swap *ps,
						t_visualizer *vs);

/*
** Draw Utils
*/

t_rectangle			*create_rectangle(int x_start,
						int x_end,
						int y_start,
						int y_end);

#endif
