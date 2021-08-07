/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:45:14 by sna               #+#    #+#             */
/*   Updated: 2021/08/08 01:50:10 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_push(t_deque *from, t_deque *to, char c)
{
	t_node *temp;

	if (from == NULL || to == NULL || !c)//from이 비어있을 때는 아무것도 수행 안함
		return ;
	temp = from->head;//from 주소 저장
	from->head = (from->head)->next;//from의 다음 리스트 주소를 from에 저장
	if (from->head == NULL)
        from->tail = NULL;
    else
		(from->head)->prev = NULL;//이전 리스트가 있다면 prev에 null 입력(이전주소 끊기?)
	if (to->head)
		(to->head)->prev = temp;//*to 주소가 존재하면 from 주소가 저장된 temp를 (*to)->prev에 입력
	else
		to->tail = temp;//아니면 *to_tail 에 temp입력
	temp->next = to->head;//temp->next 주소(다음 주소)로 *to 저장
	to->head = temp;
	(to->head)->prev = NULL;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

char	**ft_free_pw(char **new_str)
{
	size_t	i;

	i = 0;
	while (new_str[i])
	{
		free(new_str[i]);
		i++;
	}
	free(new_str);
	return (NULL);
}

int		ft_str_isdigit(char *c)
{
	int 	i;

	i = 0;
	if (c[i] == '+' || c[i] == '-')
		i++;
	while (c[i])
	{
		if (c[i] >= '0' && c[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int     check_number_test(char **av)
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

void	insert_a_deq(t_deque *a, char **av)
{
	int		i;
	int		j;
	char	**c_av;

	i = 1;
	a->head->prev = NULL;
    a->tail = a->head;
	while (av[i])
	{
		c_av = ft_split(av[i], ' ');
		j = 0;
		while (c_av[j])
		{
			if (!ft_strlen(c_av[j]))
				print_error();
			lst_addend(c_av[j], a);
			j++;
		}
		ft_free_pw(c_av);
		i++;
	}
}