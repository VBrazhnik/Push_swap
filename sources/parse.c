/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 18:08:40 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/08/26 18:08:41 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "error_message.h"
#include <stdlib.h>

static void	parse_arr(t_stack *stack,
				int argc,
				char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isint(argv[i], false))
			terminate(ERR_NAN);
		add(stack, create_elem(ft_atoi(argv[i++])));
	}
}

static void	parse_str(t_stack *stack,
				char *str)
{
	char	**numbers;
	size_t	i;

	numbers = ft_strsplit(str, ' ');
	i = 0;
	while (numbers[i])
	{
		if (!ft_isint(numbers[i], false))
			terminate(ERR_NAN);
		add(stack, create_elem(ft_atoi(numbers[i++])));
	}
	ft_strsplit_free(&numbers);
}

t_stack		*parse(int argc,
				char **argv)
{
	t_stack	*stack;

	if (!(stack = (t_stack *)ft_memalloc(sizeof(t_stack))))
		terminate(ERR_MEMALLOC);
	stack->head = NULL;
	stack->size = 0;
	stack->pairs = 0;
	stack->markup_head = NULL;
	if (argc == 2 && !ft_isnum(argv[1], 10))
		parse_str(stack, argv[1]);
	else
		parse_arr(stack, argc, argv);
	if (!stack->size)
		terminate(ERR_NO_NUMBERS);
	return (stack);
}
