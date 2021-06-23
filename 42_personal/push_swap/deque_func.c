#include "deque.h"

int    dq_get_last(t_deque *d)
{
    if (dq_is_empty(d))
    {
        write(1, "deque memory error\n", 19);
        exit(-1);
    }
    return (d->tail->data);
}

int    dq_get_first(t_deque *d)
{
    if (dq_is_empty(d))
    {
        write(1, "deque memory error\n", 19);
        exit(-1);
    }
    return (d->head->data);
}

int    dq_remove_last(t_deque *d)
{
    t_node  *rnode;
    int    rdata;

    rnode = d->tail;
    if (dq_is_empty(d))
    {
        write(1, "deque memory error\n", 19);
        exit(-1);
    }
    rdata = d->tail->data;
    d->tail = d->tail->prev;
    free(rnode);
    if (d->tail == NULL)
        d->head = NULL;
    else
        d->tail->next = NULL;
    return (rdata);
}

int    dq_remove_first(t_deque *d)
{
    t_node  *rnode;
    int    rdata;

    rnode = d->head;
    if (dq_is_empty(d))
    {
        write(1, "deque memory error\n", 19);
        exit(-1);
    }
    rdata = d->head->data;
    d->head = d->head->next;
    free(rnode);
    if (d->head == NULL)
        d->tail = NULL;
    else
        d->tail->prev = NULL;
    
    return (rdata);
}

void    dq_add_last(t_deque *d, int data)
{
    t_node  *newnode;

    newnode = (t_node *)malloc(sizeof(t_node));
    newnode->data = data;//tmp->n = (int)num
    newnode->prev = d->tail;//tmp->prev = *back;
    if (dq_is_empty(d))
        d->head = newnode;
    else
        d->tail->next = newnode;//*back->nxt = tmp;
    newnode->next = NULL;//tmp->next = null;
    d->tail = newnode;//*back = tmp;
}

void    dq_add_first(t_deque *d, int data)
{
    t_node  *newnode;

    newnode = (t_node *)malloc(sizeof(t_node));
    newnode->data = data;
    newnode->next = d->head; //이전 노드의 head(NULL을 가리키는)를 새로운 노드에 삽입
    if (dq_is_empty(d))
        d->tail = newnode;
    else
        d->head->prev = newnode;
    newnode->prev = NULL;
    d->head = newnode;
}

int     dq_is_empty(t_deque *d)
{
    if (d->head == NULL)//head가 NULL이면 비어있는 덱
        return (TRUE);
    else
        return (FALSE);
}

void    deque_init(t_deque *d)
{
    d->head = NULL;
    d->tail = NULL;
}