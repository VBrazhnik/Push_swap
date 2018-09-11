/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 21:59:11 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/08/26 21:59:12 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_elem	*get_next_min(t_stack *stack)
{
	size_t			i;
	t_bool			has_min;
	t_stack_elem	*min;
	t_stack_elem	*current;

	min = NULL;
	if (stack)
	{
		i = 0;
		has_min = false;
		current = stack->head;
		while (i < stack->size)
		{
			if ((current->index == -1)
				&& (!has_min || current->number < min->number))
			{
				has_min = true;
				min = current;
			}
			i++;
			current = current->next;
		}
	}
	return (min);
}

void				index_stack(t_stack *stack)
{
	size_t			index;
	t_stack_elem	*current;

	index = 0;
	while ((current = get_next_min(stack)))
		current->index = index++;
}
