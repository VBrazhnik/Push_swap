/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 20:15:38 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/08/26 20:15:39 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_stack *to,
			t_stack *from,
			const char *name,
			t_command_list *list)
{
	push(to, pop(from));
	if (name && !list)
		ft_putendl(name);
	if (name && list)
		add_command(list, create_command(name));
}
