/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:43:47 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/05 17:43:49 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "visualizer.h"
#include "libft.h"
#include "error_message.h"
#include "get_next_line.h"
#include <stdlib.h>

int			close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

static void	visualizer(t_visualizer *vs,
				t_push_swap *ps)
{
	size_t			size;
	char			*line;

	mlx_hook(vs->win, 17, 0, close, vs);
	draw(ps, vs);
	while ((size = get_next_line(0, &line)) > 0)
	{
		exec_command(ps->a_stack, ps->b_stack, line, false);
		free(line);
		draw(ps, vs);
	}
	mlx_loop(vs->mlx);
}

int			main(int argc,
				char **argv)
{
	t_visualizer	*vs;
	t_push_swap		*ps;

	vs = NULL;
	ps = NULL;
	if (argc >= 2)
	{
		ps = init_push_swap(argc, argv);
		vs = init_visualizer();
	}
	if (ps && ps->a_stack->size <= HEIGHT)
		visualizer(vs, ps);
	else
	{
		ft_putendl(ERR_VS_USAGE);
		ft_putendl(VS_HELP);
	}
	return (0);
}
