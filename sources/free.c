/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 22:31:17 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/07 22:31:18 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_command_list(t_command_list *list)
{
	t_command *current;
	t_command *delete;

	current = list->head;
	while (current)
	{
		delete = current;
		current = current->next;
		free(delete->name);
		free(delete);
	}
	free(list);
}

void	free_stack(t_stack *stack)
{
	size_t			i;
	t_stack_elem	*current;
	t_stack_elem	*delete;

	i = 0;
	current = stack->head;
	while (i < stack->size)
	{
		delete = current;
		current = current->next;
		free(delete);
		i++;
	}
	free(stack);
}
