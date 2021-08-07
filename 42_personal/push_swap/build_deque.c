/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_deque.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:49:23 by sna               #+#    #+#             */
/*   Updated: 2021/08/08 01:48:42 by sna              ###   ########.fr       */
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

int     check_number(int ac, char **av)
{
    int     i;
    int     j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        if (av[i][j] == '-')
            j++;
        if (!ft_isdigit(av[i][j]))
            return (0);
        while (ft_isdigit(av[i][j]))
            j++;
        if (av[i][j])
            return (0);
        i++;
    }
    return (1);
}

void    lst_addend(char *str, t_deque *a)
{
    long    num;

    num = ft_atoi(str);
    if (num > INT_MAX || num < INT_MIN)
        print_error();
    if (a == NULL)
        return ;
    dq_add_last(a, (int)num);
}

void    build_deque(t_deque *a, t_deque *b, int ac, char **av)
{
    t_node  *temp;
    //int     i;

    //i = 1;
    a->head = malloc(sizeof(t_node));
    if (!check_number_test(av) || !a->head)
        print_error();
    deque_init(b);
    /*
    a->head->data = ft_atoi(av[i++]);
    a->head->prev = NULL;
    a->tail = a->head;
    while (i < ac)
        lst_addend(av[i++], a);
    */
    insert_a_deq(a, av);
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