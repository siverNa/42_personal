/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_deque.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:49:23 by sna               #+#    #+#             */
/*   Updated: 2021/06/22 19:14:48 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_error()
{
    write(1, "error\n", 6);
    exit(1);
}

int     check_number(int ac, char **av)
{
    int i;
    int j;

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
        if (av[i][j] == '\0')
            return (0);
        i++;
    }
}

void    build_deque(t_deque *a, t_deque *b, int ac, char **av)
{
    int i;

    i = 1;
    if (!check_number(ac, av) || (a->head = malloc(sizeof(t_deque))))
        print_error();
}