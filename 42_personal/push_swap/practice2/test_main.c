#include <stdio.h>
#include "deque.h"

int main()
{
    //deque 생성 및 초기화
    t_deque d;
    deque_init(&d);

    //데이터 넣기 1차
    dq_add_first(&d, 3);
    dq_add_first(&d, 2);
    dq_add_first(&d, 1);

    dq_add_last(&d, 4);
    dq_add_last(&d, 5);
    dq_add_last(&d, 6);

    //데이터 꺼내기 1차
    while (!dq_is_empty(&d))
        printf("%d ",dq_remove_first(&d));
    printf("\n");

    //데이터 넣기 2차
    dq_add_first(&d, 3);
    dq_add_first(&d, 2);
    dq_add_first(&d, 1);

    dq_add_last(&d, 4);
    dq_add_last(&d, 5);
    dq_add_last(&d, 6);

    //데이터 꺼내기 2차
    while (!dq_is_empty(&d))
        printf("%d ",dq_remove_last(&d));
    printf("\n");

    return(0);
}