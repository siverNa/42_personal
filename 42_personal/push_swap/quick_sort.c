/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:28:00 by sna               #+#    #+#             */
/*   Updated: 2021/07/06 18:52:06 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quick_swap(int *arr, int a, int b) // a,b 스왑 함수 
{
    int temp;
    
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int *arr, int left, int right)
{
    int pivot; // 피벗의 위치는 가장 왼쪽에서 시작
    int low;
    int high;

    pivot = arr[left];
    low = left + 1;
    high = right;
 
    while (low <= high) // 교차되기 전까지 반복한다 
    {
        while (low <= right && pivot >= arr[low]) // 피벗보다 큰 값을 찾는 과정 
            low++; // low를 오른쪽으로 이동 
        while (high >= (left + 1) && pivot <= arr[high]) // 피벗보다 작은 값을 찾는 과정 
            high--; // high를 왼쪽으로 이동
        if (low <= high)// 교차되지 않은 상태이면 스왑 과정 실행 
            quick_swap(arr, low, high); //low와 high를 스왑 
    }
    quick_swap(arr, left, high); // 피벗과 high가 가리키는 대상을 교환 
    return (high);  // 옮겨진 피벗의 위치정보를 반환 
}
 
 
void quicksort(int *arr, int left, int right)
{
    if (left <= right)
    {
        int pivot;

        pivot = partition(arr, left, right); // 둘로 나누어서
        quicksort(arr, left, pivot - 1); // 왼쪽 영역을 정렬한다.
        quicksort(arr, pivot + 1, right); // 오른쪽 영역을 정렬한다.
    }
}

void sort(t_deque *a, int *arr, int n)
{
    t_node *temp;
    int     i;

    temp = a->head;
    i = 0;
    while (temp)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    quicksort(arr, 0, n - 1);
}