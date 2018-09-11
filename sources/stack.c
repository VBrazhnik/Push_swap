/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 18:56:14 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/08/26 18:56:15 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error_message.h"

t_stack_elem	*create_elem(int number)
{
	t_stack_elem	*new;

	if (!(new = (t_stack_elem *)ft_memalloc(sizeof(t_stack_elem))))
		terminate(ERR_MEMALLOC);
	new->number = number;
	new->index = -1;
	new->keep = false;
	new->keep_in_stack = false;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void			add(t_stack *stack,
					t_stack_elem *elem)
{
	t_stack_elem	*tail;

	if (stack && elem)
	{
		if (!stack->head)
		{
			stack->head = elem;
			stack->head->previous = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			tail = stack->head->previous;
			elem->previous = tail;
			tail->next = elem;
			elem->next = stack->head;
			stack->head->previous = elem;
		}
		stack->size++;
	}
}

void			push(t_stack *stack,
					t_stack_elem *elem)
{
	t_stack_elem	*tail;

	if (stack && elem)
	{
		if (!stack->head)
		{
			stack->head = elem;
			stack->head->previous = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			tail = stack->head->previous;
			elem->previous = tail;
			tail->next = elem;
			elem->next = stack->head;
			stack->head->previous = elem;
			stack->head = elem;
		}
		stack->size++;
	}
}

t_stack_elem	*pop(t_stack *stack)
{
	t_stack_elem	*elem;

	elem = NULL;
	if (stack && stack->size)
	{
		if (stack->size == 1)
		{
			elem = stack->head;
			stack->head = NULL;
			elem->previous = NULL;
			elem->next = NULL;
		}
		else
		{
			elem = stack->head;
			stack->head = stack->head->next;
			elem->previous->next = elem->next;
			elem->next->previous = elem->previous;
			elem->previous = NULL;
			elem->next = NULL;
		}
		stack->size--;
	}
	return (elem);
}
