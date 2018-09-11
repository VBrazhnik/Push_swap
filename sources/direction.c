/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 18:37:46 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/06 18:37:47 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_elem	*find_a_elem(t_stack *a_stack,
						int index)
{
	t_stack_elem	*current;

	current = a_stack->markup_head;
	if (index < current->index)
	{
		while (index < current->previous->index
			&& current->index > current->previous->index)
			current = current->previous;
	}
	else
	{
		while (index > current->index
			&& current->index < current->next->index)
			current = current->next;
		if (index > current->index && current->index > current->next->index)
			current = current->next;
	}
	return (current);
}

static void			estimate_direction(t_stack *stack,
						int index,
						size_t *rx_size,
						size_t *rrx_size)
{
	t_stack_elem	*current;

	if (stack && stack->head)
	{
		current = stack->head;
		while (current->index != index)
		{
			(*rx_size)++;
			current = current->next;
		}
		current = stack->head;
		while (current->index != index)
		{
			(*rrx_size)++;
			current = current->previous;
		}
	}
}

static void			set_direction(size_t size,
						t_shift_info new_shift_info,
						t_shift_info *shift_info)
{
	if (!shift_info->is_set || size < shift_info->size)
	{
		shift_info->a_elem = new_shift_info.a_elem;
		shift_info->b_elem = new_shift_info.b_elem;
		shift_info->a_direction = new_shift_info.a_direction;
		shift_info->b_direction = new_shift_info.b_direction;
		shift_info->size = size;
		shift_info->is_set = true;
	}
}

static void			optimal_direction(t_stack *a_stack,
						t_stack *b_stack,
						t_stack_elem *b_elem,
						t_shift_info *shift_info)
{
	t_shift_info	new_shift_info;
	size_t			ra_size;
	size_t			rra_size;
	size_t			rb_size;
	size_t			rrb_size;

	ra_size = 0;
	rra_size = 0;
	rb_size = 0;
	rrb_size = 0;
	new_shift_info.a_elem = find_a_elem(a_stack, b_elem->index);
	new_shift_info.b_elem = b_elem;
	estimate_direction(a_stack, new_shift_info.a_elem->index,
						&ra_size, &rra_size);
	estimate_direction(b_stack, b_elem->index,
						&rb_size, &rrb_size);
	new_shift_info.a_direction = R;
	new_shift_info.b_direction = R;
	set_direction(FT_MAX(ra_size, rb_size), new_shift_info, shift_info);
	new_shift_info.a_direction = RR;
	set_direction(rra_size + rb_size, new_shift_info, shift_info);
	new_shift_info.b_direction = RR;
	set_direction(FT_MAX(rra_size, rrb_size), new_shift_info, shift_info);
	new_shift_info.a_direction = R;
	set_direction(ra_size + rrb_size, new_shift_info, shift_info);
}

void				opt_direction(t_stack *a_stack,
						t_stack *b_stack,
						t_shift_info *shift_info)
{
	size_t			i;
	t_stack_elem	*current;

	if (b_stack)
	{
		i = 0;
		current = b_stack->head;
		while (i < b_stack->size)
		{
			optimal_direction(a_stack, b_stack, current, shift_info);
			i++;
			current = current->next;
		}
	}
}
