/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 19:42:34 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/06 19:42:35 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"
#include "mlx.h"
#include "error_message.h"
#include <stdlib.h>

static void	put_pixel(t_visualizer *vs,
				int x,
				int y,
				int color)
{
	int		i;

	i = (x * vs->bits_per_pixel / 8) + (y * vs->size_line);
	vs->data_addr[i] = color;
	vs->data_addr[++i] = color >> 8;
	vs->data_addr[++i] = color >> 16;
}

static void	draw_rectangle(t_visualizer *vs,
				t_rectangle *rectangle)
{
	int	x;
	int	y;
	int	width;
	int	height;

	x = rectangle->x_start;
	width = rectangle->x_end;
	height = rectangle->y_end;
	while (x < width)
	{
		y = rectangle->y_start;
		while (y < height)
		{
			put_pixel(vs, x, y, YELLOW);
			y++;
		}
		x++;
	}
}

static void	draw_stack(t_push_swap *ps,
				t_visualizer *vs,
				t_stack *stack,
				int x_start)
{
	size_t			i;
	t_stack_elem	*current;
	t_rectangle		*rectangle;

	i = 0;
	current = stack->head;
	while (i < stack->size)
	{
		rectangle = create_rectangle(x_start,
			x_start + (current->index + 1) * ps->width_coeff,
			i * ps->height_coeff, (i + 1) * ps->height_coeff);
		draw_rectangle(vs, rectangle);
		free(rectangle);
		i++;
		current = current->next;
	}
}

static void	draw_background(t_visualizer *vs)
{
	int	*image;
	int	i;

	ft_bzero(vs->data_addr, WIDTH * HEIGHT * (vs->bits_per_pixel / 8));
	image = (int *)(vs->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = (i % WIDTH < WIDTH / 2) ? GREY_1 : GREY_2;
		i++;
	}
}

void		draw(t_push_swap *ps,
				t_visualizer *vs)
{
	draw_background(vs);
	draw_stack(ps, vs, ps->a_stack, 0);
	draw_stack(ps, vs, ps->b_stack, WIDTH / 2);
	mlx_put_image_to_window(vs->mlx, vs->win, vs->img, 0, 0);
	mlx_do_sync(vs->mlx);
}
