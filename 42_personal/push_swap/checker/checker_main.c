/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:17:18 by sna               #+#    #+#             */
/*   Updated: 2021/08/20 22:11:02 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	perform_exit(t_deque *a, t_deque *b, int input)
{
	t_node	*temp;

	while (a->head)
	{
		temp = a->head;
		a->head = a->head->next;
		free(temp);
	}
	while (b->head)
	{
		temp = b->head;
		b->head = b->head->next;
		free(temp);
	}
	if (input)
		write(0, "OK\n", 3);
	if (!input)
		write(0, "KO\n", 3);
	exit(1);
}

void	check_char(char *line, t_deque *a, t_deque *b)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb")
		|| !ft_strcmp(line, "ss"))
		swap_perform(line, &a, &b);
	else if (!ft_strcmp(line, "pa"))
		push(&b, &a, 'a');
	else if (!ft_strcmp(line, "pb"))
		push(&a, &b, 'b');
	else if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rb")
		|| !ft_strcmp(line, "rr"))
		rotate_perform(line, &a, &b);
	else if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb")
		|| !ft_strcmp(line, "rrr"))
		rev_rotate_perform(line, &a, &b);
	else
		perform_exit(&a, &b, 0);
}

int	main(int ac, char **av)
{
	t_deque	a;
	t_deque	b;
	char	*line;

	build_deque(&a, &b, ac, av);
	while (get_next_line(0, &line) > 0)
	{
		check_char(line, &a, &b);
		free(line);
	}
	if (!a_is_sorted(&a) || b.head)
		perform_exit(&a, &b, 0);
	perform_exit(&a, &b, 1);
}
