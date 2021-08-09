/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 16:14:19 by sna               #+#    #+#             */
/*   Updated: 2021/08/09 23:18:59 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
char    **move_av_to_cav(char **av)
{
    int     i;
    int     j;
    int     k;
    char    **c_av;
    char    **all_arr;

    i = 1;
    k = 0;
    while (av[i])
    {
        j = 0;
        c_av = ft_split(av[i], ' ');
        while (c_av[j])
            all_arr[k++] = c_av[j++];
        ft_free_pw(c_av);
    }
    return (all_arr);
}
*/
void    lst_addend_test(char *str, t_deque *a, int *j)
{
    long    num;

    num = ft_atoi_pw(str, j);
    if (num > INT_MAX || num < INT_MIN)
        print_error();
    if (a == NULL)
        return ;
    dq_add_last(a, (int)num);
}

int     ft_atoi_pw(char *str, int *i)
{
    long    num;
    int     sign;

    num = 0;
    sign = 1;
    if (str[*i] == '-' || str[*i] == '+')
    {
        if (str[*i] == '-')
            sign = -1;
        ++*i;
    }
    while (str[*i])
    {
        if (str[*i] < '0' || str[*i] > '9')
            break ;
        num = num * 10 + (str[*i] - '0');
        ++*i;
    }
    while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
        ++*i;
    if (num * sign < -2147483648 || num * sign > 2147483647)
        print_error();
    return (num * sign);
}