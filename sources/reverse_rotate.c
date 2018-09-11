/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 20:14:41 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/08/26 20:14:43 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_stack *stack,
			const char *name,
			t_command_list *list)
{
	if (stack && stack->head)
		stack->head = stack->head->previous;
	if (name && !list)
		ft_putendl(name);
	if (name && list)
		add_command(list, create_command(name));
}

void	rrr(t_stack *a,
			t_stack *b,
			const char *name,
			t_command_list *list)
{
	rrx(a, NULL, NULL);
	rrx(b, NULL, NULL);
	if (name && !list)
		ft_putendl(name);
	if (name && list)
		add_command(list, create_command(name));
}
