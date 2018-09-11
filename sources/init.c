/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:39:09 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/05 19:39:10 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"
#include "mlx.h"
#include "push_swap.h"
#include "error_message.h"

t_stack			*init_stack(void)
{
	t_stack *stack;

	if (!(stack = (t_stack *)ft_memalloc(sizeof(t_stack))))
		terminate(ERR_MEMALLOC);
	stack->head = NULL;
	stack->size = 0;
	stack->pairs = 0;
	stack->markup_head = NULL;
	return (stack);
}

t_command_list	*init_command_list(void)
{
	t_command_list *list;

	if (!(list = (t_command_list *)ft_memalloc(sizeof(t_command_list))))
		terminate(ERR_MEMALLOC);
	list->size = 0;
	list->head = NULL;
	return (list);
}

t_push_swap		*init_push_swap(int argc,
					char **argv)
{
	t_push_swap *ps;

	if (!(ps = (t_push_swap *)ft_memalloc(sizeof(t_push_swap))))
		terminate(ERR_MEMALLOC);
	ps->a_stack = parse(argc, argv);
	ps->b_stack = init_stack();
	check_dups(ps->a_stack);
	index_stack(ps->a_stack);
	ps->width_coeff = WIDTH / 2 / ps->a_stack->size;
	ps->height_coeff = HEIGHT / ps->a_stack->size;
	return (ps);
}

t_visualizer	*init_visualizer(void)
{
	t_visualizer *vs;

	if (!(vs = (t_visualizer *)ft_memalloc(sizeof(t_visualizer))))
		terminate(ERR_MEMALLOC);
	if (!(vs->mlx = mlx_init()))
		terminate(ERR_VS_INIT);
	if (!(vs->win = mlx_new_window(vs->mlx, WIDTH, HEIGHT, "Push Swap")))
		terminate(ERR_VS_INIT);
	if (!(vs->img = mlx_new_image(vs->mlx, WIDTH, HEIGHT)))
		terminate(ERR_VS_INIT);
	vs->data_addr = mlx_get_data_addr(vs->img, &(vs->bits_per_pixel),
										&(vs->size_line), &(vs->endian));
	return (vs);
}
