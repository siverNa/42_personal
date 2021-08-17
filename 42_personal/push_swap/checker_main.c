/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:17:18 by sna               #+#    #+#             */
/*   Updated: 2021/08/17 18:15:16 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_putstr("OK\n");
	if (!input)
		ft_putstr("KO\n");
	exit(1);
}

int main(int ac, char **av)
{
	t_deque	a;
	t_deque	b;
	char	*line;

    build_deque(&a, &b, ac, av);
    while (get_next_line(0, &line) > 0)
    {
		if (!STRCMP(line, "sa") || !STRCMP(line, "sa") || !STRCMP(line, "sa"))
			swap_perform(line, &a, &b);
		else if (!STRCMP(line, "pa"))
			push(&b, &a, 'a');
		else if (!STRCMP(line, "pb"))
			push(&a, &b, 'b');
		else if (!STRCMP(line, "ra") || !STRCMP(line, "rb") ||
			!STRCMP(line, "rr"))
			rotate_perform(line, &a, &b);
		else if (!STRCMP(line, "rra") || !STRCMP(line, "rrb") ||
			!STRCMP(line, "rrr"))
			rev_rotate_perform(line, &a, &b);
		else
			perform_exit(&a, &b, 0);
		free(line);
	}
	if (!a_is_sorted(&a) || b.head)
		perform_exit(&a, &b, 0);
	perform_exit(&a, &b, 1);
}