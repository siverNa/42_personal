/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:32:12 by sna               #+#    #+#             */
/*   Updated: 2021/06/24 17:42:55 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
    t_deque a;
    t_deque b;
    
    build_deque(&a, &b, ac, av);

    while (!dq_is_empty(&a))
        printf("%d ",dq_remove_first(&a));
    printf("\n");
}