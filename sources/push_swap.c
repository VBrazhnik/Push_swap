/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:44:41 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/08/24 15:44:42 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error_message.h"

int		main(int argc,
			char **argv)
{
	t_stack				*stack_index;
	t_stack				*stack_gt;
	t_command_list		*commands_index;
	t_command_list		*commands_gt;

	if (argc >= 2)
	{
		check_dups((stack_index = parse(argc, argv)));
		index_stack(stack_index);
		opt_markup_stack(stack_index, &markup_stack_index);
		commands_index = solve(stack_index, &markup_stack_index);
		free_stack(stack_index);
		index_stack(stack_gt = parse(argc, argv));
		opt_markup_stack(stack_gt, &markup_stack_gt);
		commands_gt = solve(stack_gt, &markup_stack_gt);
		free_stack(stack_gt);
		print_commands((commands_index->size < commands_gt->size) ?
			commands_index : commands_gt);
		free_command_list(commands_index);
		free_command_list(commands_gt);
	}
	else
		ft_putendl(ERR_PS_USAGE);
	return (0);
}
