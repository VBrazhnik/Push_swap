/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:00:58 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/08/28 15:01:00 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	markup_stack_index(t_stack *stack,
			t_stack_elem *markup_head)
{
	ssize_t			index;
	size_t			pairs;
	t_stack_elem	*current;

	pairs = 0;
	if (stack && markup_head)
	{
		index = markup_head->index;
		markup_head->keep_in_stack = true;
		current = markup_head->next;
		while (current != markup_head)
		{
			if (current->index == index + 1)
			{
				pairs++;
				index++;
				current->keep_in_stack = true;
			}
			else
				current->keep_in_stack = false;
			current = current->next;
		}
	}
	return (pairs);
}

size_t	markup_stack_gt(t_stack *stack,
			t_stack_elem *markup_head)
{
	ssize_t			index;
	size_t			pairs;
	t_stack_elem	*current;

	pairs = 0;
	if (stack && markup_head)
	{
		index = markup_head->index;
		markup_head->keep_in_stack = true;
		current = markup_head->next;
		while (current != markup_head)
		{
			if (current->index > index)
			{
				pairs++;
				index = current->index;
				current->keep_in_stack = true;
			}
			else
				current->keep_in_stack = false;
			current = current->next;
		}
	}
	return (pairs);
}

void	opt_markup_stack(t_stack *stack,
			size_t (*markup_stack)(t_stack *, t_stack_elem *))
{
	size_t			i;
	size_t			current_pairs;
	t_stack_elem	*current;

	if (stack)
	{
		i = 0;
		current = stack->head;
		while (i < stack->size)
		{
			current_pairs = markup_stack(stack, current);
			if (current_pairs > stack->pairs)
			{
				stack->markup_head = current;
				stack->pairs = current_pairs;
			}
			else if (current_pairs == stack->pairs &&
				(!stack->markup_head ||
					current->number < stack->markup_head->number))
				stack->markup_head = current;
			i++;
			current = current->next;
		}
	}
	markup_stack(stack, stack->markup_head);
}
