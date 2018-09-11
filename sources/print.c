/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 18:13:52 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/08/26 18:13:53 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"
#include "push_swap.h"
#include "libft.h"

static void	print_int(int number,
				int len)
{
	int	spaces;
	int	numlen;

	numlen = ft_signedlen(number, 10);
	spaces = len - numlen;
	while (spaces > 0)
	{
		ft_putchar(' ');
		spaces--;
	}
	ft_putnbr(number);
}

static void	print_stack(t_stack *stack,
				t_stack_elem **current,
				size_t i)
{
	if (i < stack->size)
	{
		ft_putchar(' ');
		print_int((*current)->number, ft_signedlen(FT_INT_MIN, 10));
		ft_putchar(' ');
		(*current) = (*current)->next;
	}
	else
		ft_putstr("             ");
}

void		print_stacks(t_stack *a_stack,
				t_stack *b_stack,
				t_bool color)
{
	size_t			i;
	t_stack_elem	*a_current;
	t_stack_elem	*b_current;

	i = 0;
	a_current = a_stack->head;
	b_current = b_stack->head;
	ft_putendl("+------A------+------B------+");
	while (i < a_stack->size || i < b_stack->size)
	{
		if (!(i % 2) && color)
			ft_putstr(REVERSE);
		ft_putchar('|');
		print_stack(a_stack, &a_current, i);
		ft_putchar('|');
		print_stack(b_stack, &b_current, i);
		ft_putchar('|');
		if (!(i % 2) && color)
			ft_putstr(RESET_REVERSE);
		ft_putstr("\n");
		i++;
	}
	ft_putendl("+-------------+-------------+");
}
