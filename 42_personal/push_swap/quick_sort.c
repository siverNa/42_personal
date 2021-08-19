/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:28:00 by sna               #+#    #+#             */
/*   Updated: 2021/08/19 18:32:55 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_swap(int *arr, int a, int b)
{
	int		temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int	partition(int *arr, int left, int right)
{
	int		pivot;
	int		low;
	int		high;

	pivot = arr[left];
	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (low <= right && pivot >= arr[low])
			low++;
		while (high >= (left + 1) && pivot <= arr[high])
			high--;
		if (low <= high)
			quick_swap(arr, low, high);
	}
	quick_swap(arr, left, high);
	return (high);
}

void	quicksort(int *arr, int left, int right)
{
	int		pivot;

	if (left <= right)
	{
		pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
	}
}

void	sort(t_deque *a, int *arr, int n)
{
	t_node	*temp;
	int		i;

	temp = a->head;
	i = 0;
	while (temp)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
	quicksort(arr, 0, n - 1);
}
