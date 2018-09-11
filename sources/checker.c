/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 20:44:56 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/08/29 20:44:57 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include "error_message.h"
#include <stdlib.h>

static t_bool	is_sorted(t_stack *stack)
{
	size_t			i;
	t_stack_elem	*current;
	int				previous_number;

	i = 1;
	current = stack->head->next;
	previous_number = stack->head->number;
	while (i < stack->size)
	{
		if (current->number < previous_number)
			return (false);
		previous_number = current->number;
		i++;
		current = current->next;
	}
	return (true);
}

static void		checker(int argc,
					char **argv,
					t_bool verbose,
					t_bool color)
{
	t_stack *a_stack;
	t_stack *b_stack;
	char	*line;
	ssize_t	size;

	b_stack = init_stack();
	check_dups((a_stack = parse(argc, argv)));
	ft_putstr((verbose) ? "> init\n" : NULL);
	if (verbose)
		print_stacks(a_stack, b_stack, color);
	while ((size = get_next_line(0, &line)) > 0)
	{
		exec_command(a_stack, b_stack, line, verbose);
		if (verbose)
			print_stacks(a_stack, b_stack, color);
		free(line);
	}
	if (size == -1)
		terminate(ERR_GNL);
	if (b_stack->head == NULL && is_sorted(a_stack))
		ft_putendl((color) ? COLOR_OK : OK);
	else
		ft_putendl((color) ? COLOR_KO : KO);
	free_stack(a_stack);
	free_stack(b_stack);
}

int				main(int argc,
					char **argv)
{
	t_bool	verbose;
	t_bool	color;
	t_bool	help;

	verbose = false;
	color = false;
	help = false;
	while (argc >= 2 &&
		(!ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1], "-c")
		|| !ft_strcmp(argv[1], "-h")))
	{
		if (!ft_strcmp(argv[1], "-v"))
			verbose = true;
		else if (!ft_strcmp(argv[1], "-c"))
			color = true;
		else if (!ft_strcmp(argv[1], "-h"))
			help = true;
		argv++;
		argc--;
	}
	if (argc >= 2 && !help)
		checker(argc, argv, verbose, color);
	else if (help)
		ft_putendl(CH_HELP);
	return (0);
}
