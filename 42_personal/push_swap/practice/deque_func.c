#include "dec_queue.h"
#include <stdio.h>

/*
** 덱을 MAX_DEQUE_SIZE 만큼 동적할당하는 함수
*/
int     init_deque(t_deque *q)
{
    q->data = (int *)malloc(sizeof(int) * MAX_DEQUE_SIZE);
    if (!q->data)
        return (0);
    q->front = 0;
    q->rear = 0;
    return (1);
}

/*
** 덱이 비어있는지 확인하는 함수.
** 비어있는 덱은 front == rear 인 상태이므로 이를 이용
*/
int     is_empty(t_deque *q)
{
    if (q->front == q->rear)
        return (TRUE);
    else
        return (FALSE);
}

/*
** 현재 덱의 rear 값 반환
*/
int     get_rear(t_deque *q)
{
    if (is_empty(q))
    {
        write(1, "empty deque\n", 12);
        return (0);
    }
    return (q->data[q->rear]);
}

/*
** 현재 덱의 front 값 반환
*/
int     get_front(t_deque *q)
{
    if (is_empty(q))
    {
        write(1, "empty deque\n", 12);
        return (0);
    }
    return (q->data[(q->front + 1) % MAX_DEQUE_SIZE]);
}

/*
** 현재 덱이 포화상태인지 확인
** 그냥 rear == front 를 하면 포화상태인지, 공백상태인지 알 수 없으므로
** 비워놓은 한 칸을 이용해 포화 유무를 비교
*/
int     is_full(t_deque *q)
{
    if (((q->rear + 1) % MAX_DEQUE_SIZE) == q->front)
        return (TRUE);
    else
        return (FALSE);
}

/*
** 덱의 뒤쪽에 rear 을 이동시키면서 값 삽입
*/
void    add_rear(t_deque *q, int data)
{
    if (is_full(q))
    {
        write(1, "full deque\n", 11);
        return ;
    }
    q->rear = (q->rear + 1) % MAX_DEQUE_SIZE;
    q->data[q->rear] = data;
}

/*
** 덱의 앞쪽에 front를 이동시키면서 값 삽입
*/
void    add_front(t_deque *q, int data)
{
    if (is_full(q))
    {
        write(1, "full deque\n", 11);
        return ;
    }
    q->data[q->front] = data;
    q->front = (q->front - 1 + MAX_DEQUE_SIZE)
    % MAX_DEQUE_SIZE;
}

/*
** 덱의 전단에서 데이터 삭제
*/
int     delete_front(t_deque *q)
{
    int tmp;

    if (is_empty(q))
    {
        write(1, "empty deque\n", 12);
        return (ERROR);
    }
    tmp = get_front(q);
    q->front = (q->front + 1) % MAX_DEQUE_SIZE;
    return (tmp);
}

/*
** 덱의 후단에서 데이터 삭제
*/
int     delete_rear(t_deque *q)
{
    int tmp;

    if (is_empty(q))
    {
        write(1, "empty deque\n", 12);
        return (ERROR);
    }
    tmp = q->data[q->rear];
    q->rear = (q->rear - 1 + MAX_DEQUE_SIZE)
    % MAX_DEQUE_SIZE;
    return (tmp);
}

/*
** 덱의 모든 요소 print
*/
int    print_deque(t_deque *q)
{
    int i;

    i = (q->front + 1) % MAX_DEQUE_SIZE;
    printf("DEQUE(front = %d rear = %d) = ", q->front, q->rear);
    if (is_empty(q))
    {
        printf("empty queue\n");
        return (0);
    }
    while (i != q->rear)
    {
        printf("%d | ",q->data[i]);
        i = (i + 1) % MAX_DEQUE_SIZE;
    }
    printf("%d\n",q->data[i]);
    return (1);
}