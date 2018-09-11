/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:44:24 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/08/24 15:44:25 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"

# define OK "OK"
# define KO "KO"

# define COLOR_OK "\e[32mOK\e[39m"
# define COLOR_KO "\e[31mKO\e[39m"

typedef enum
{
	R,
	RR
}	t_direction;

typedef struct			s_stack_elem
{
	int					number;
	ssize_t				index;
	t_bool				keep_in_stack;
	t_bool				keep;
	struct s_stack_elem	*previous;
	struct s_stack_elem *next;
}						t_stack_elem;

typedef struct			s_stack
{
	t_stack_elem		*head;
	size_t				size;
	size_t				pairs;
	t_stack_elem		*markup_head;
	t_stack_elem		*markup;
}						t_stack;

typedef struct			s_shift_info
{
	t_stack_elem		*a_elem;
	t_stack_elem		*b_elem;
	int					a_direction;
	int					b_direction;
	size_t				size;
	t_bool				is_set;
}						t_shift_info;

typedef struct			s_command
{
	char				*name;
	struct s_command	*next;
}						t_command;

typedef struct			s_command_list
{
	size_t				size;
	t_command			*head;
}						t_command_list;

/*
** Parse
*/

t_stack					*parse(int argc,
							char **argv);

/*
** Validate
*/

void					check_dups(t_stack *stack);

/*
** Stack
*/

t_stack_elem			*create_elem(int number);

void					add(t_stack *stack,
							t_stack_elem *elem);

void					push(t_stack *stack,
							t_stack_elem *elem);

t_stack_elem			*pop(t_stack *stack);

/*
** Index
*/

void					index_stack(t_stack *stack);

/*
** Markup
*/

size_t					markup_stack_index(t_stack *stack,
							t_stack_elem *markup_head);

size_t					markup_stack_gt(t_stack *stack,
							t_stack_elem *markup_head);

void					opt_markup_stack(t_stack *stack,
							size_t (*markup_stack)(t_stack *, t_stack_elem *));

/*
** Command
*/

void					rx(t_stack *stack,
							const char *name,
							t_command_list *list);

void					rr(t_stack *a,
							t_stack *b,
							const char *name,
							t_command_list *list);

void					rrx(t_stack *stack,
							const char *name,
							t_command_list *list);

void					rrr(t_stack *a,
							t_stack *b,
							const char *name,
							t_command_list *list);

void					px(t_stack *to,
							t_stack *from,
							const char *name,
							t_command_list *list);

void					sx(t_stack *stack,
							const char *name,
							t_command_list *list);

void					ss(t_stack *a,
							t_stack *b,
							const char *name,
							t_command_list *list);

/*
** Solve
*/

t_command_list			*solve(t_stack *a_stack,
							size_t (*markup_stack)(t_stack *, t_stack_elem *));

void					solve_a(t_stack *a_stack,
							t_stack *b_stack,
							size_t (*markup_stack)(t_stack *, t_stack_elem *),
							t_command_list *command_list);

void					solve_b(t_stack *a_stack,
							t_stack *b_stack,
							t_command_list *command_list);

/*
** Direction
*/

void					opt_direction(t_stack *a_stack,
							t_stack *b_stack,
							t_shift_info *shift_info);

/*
** Print
*/

void					print_stacks(t_stack *a_stack,
							t_stack *b_stack,
							t_bool color);

/*
** Utils
*/

void					terminate(const char *str);

/*
** Init
*/

t_stack					*init_stack(void);

t_command_list			*init_command_list(void);

/*
** Command
*/

t_command				*create_command(const char *str);

void					add_command(t_command_list *list,
							t_command *command);

void					print_commands(t_command_list *list);

void					exec_command(t_stack *a_stack,
							t_stack *b_stack,
							const char *operation,
							t_bool verbose);

/*
** Free
*/

void					free_strsplit_arr(char **arr);

void					free_command_list(t_command_list *list);

void					free_stack(t_stack *stack);

#endif
