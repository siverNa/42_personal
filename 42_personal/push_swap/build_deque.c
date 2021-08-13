/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_deque.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:49:23 by sna               #+#    #+#             */
/*   Updated: 2021/08/13 17:21:49 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_error()
{
    write(1, "error\n", 6);
    exit(1);
}

int     check_overlap(t_deque *q, int ac)
{
    t_node  *temp;
    int     i;
    int     j;
    int     k;
    int     arr[ac + 1];

    temp = q->head;
    i = 0;
    while (temp)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    j = -1;
    while (j++ < i)
    {
        k = j;
        while (++k < i)
            if (arr[j] == arr[k])
                return (0);
    }
    return (1);
}

int     check_number(char **av)
{
    int 	i;
	int		j;
	char 	**c_av;

	i = 0;
	while (av[++i])
	{
		c_av = ft_split(av[i], ' ');
		j = -1;
		while (c_av[++j])
		{
			if (!ft_str_isdigit(c_av[j]))
			{
				ft_free_pw(c_av);
				return (0);
			}
		}
		ft_free_pw(c_av);
	}
	write(1, "number checked\n", 16);
	return (1);
}

void    lst_addend(char *str, t_deque *a, int *j)
{
    long    num;

    num = ft_atoi_pw(str, j);
    if (num > INT_MAX || num < INT_MIN)
        print_error();
    if (a == NULL)
        return ;
    dq_add_last(a, (int)num);
}

void    build_deque(t_deque *a, t_deque *b, int ac, char **av)
{
    t_node  *temp;

    a->head = 0;
    a->tail = 0;
    if (!check_number(av))
        print_error();
    deque_init(b);
    insert_a_deq(a, av, ac);
    if (!check_overlap(a, ac))
    {
        while (a->head)
        {
            temp = a->head;
            a->head = a->head->next;
            free(temp);
        }
        print_error();
    }
}