/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 19:54:34 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/08/26 19:54:35 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error_message.h"

void	check_dups(t_stack *stack)
{
	size_t			i;
	t_stack_elem	*current_i;
	t_stack_elem	*current_j;

	i = 0;
	current_i = stack->head;
	while (i < stack->size)
	{
		current_j = current_i->next;
		while (current_j != current_i)
		{
			if (current_i->number == current_j->number)
				terminate(ERR_DUPLICATE);
			current_j = current_j->next;
		}
		i++;
		current_i = current_i->next;
	}
}
