/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 20:36:30 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/03 20:36:31 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error_message.h"

t_command		*create_command(const char *name)
{
	t_command *command;

	if (!(command = (t_command *)ft_memalloc(sizeof(t_command))))
		terminate(ERR_MEMALLOC);
	if (!(command->name = ft_strdup(name)))
		terminate(ERR_MEMALLOC);
	command->next = NULL;
	return (command);
}

void			add_command(t_command_list *list,
					t_command *command)
{
	t_command *last;

	if (list && command)
	{
		if (!list->head)
			list->head = command;
		else
		{
			last = list->head;
			while (last->next)
				last = last->next;
			last->next = command;
		}
		list->size++;
	}
}

void			print_commands(t_command_list *list)
{
	t_command *current;

	current = list->head;
	while (current)
	{
		ft_putendl(current->name);
		current = current->next;
	}
}

void			exec_command(t_stack *a_stack,
					t_stack *b_stack,
					const char *operation,
					t_bool verbose)
{
	ft_putstr((verbose) ? "> " : NULL);
	if (ft_strequ(operation, "sa"))
		sx(a_stack, (verbose) ? "sa" : NULL, NULL);
	else if (ft_strequ(operation, "sb"))
		sx(b_stack, (verbose) ? "sb" : NULL, NULL);
	else if (ft_strequ(operation, "ss"))
		ss(a_stack, b_stack, (verbose) ? "ss" : NULL, NULL);
	else if (ft_strequ(operation, "pa"))
		px(a_stack, b_stack, (verbose) ? "pa" : NULL, NULL);
	else if (ft_strequ(operation, "pb"))
		px(b_stack, a_stack, (verbose) ? "pb" : NULL, NULL);
	else if (ft_strequ(operation, "ra"))
		rx(a_stack, (verbose) ? "ra" : NULL, NULL);
	else if (ft_strequ(operation, "rb"))
		rx(b_stack, (verbose) ? "rb" : NULL, NULL);
	else if (ft_strequ(operation, "rr"))
		rr(a_stack, b_stack, (verbose) ? "rr" : NULL, NULL);
	else if (ft_strequ(operation, "rra"))
		rrx(a_stack, (verbose) ? "rra" : NULL, NULL);
	else if (ft_strequ(operation, "rrb"))
		rrx(b_stack, (verbose) ? "rrb" : NULL, NULL);
	else if (ft_strequ(operation, "rrr"))
		rrr(a_stack, b_stack, (verbose) ? "rrr" : NULL, NULL);
	else
		terminate(ERR_OPERATION);
}
