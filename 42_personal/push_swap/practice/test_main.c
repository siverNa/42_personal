#include <stdio.h>
#include <stdlib.h>
#include "dec_queue.h"


int main()
{
    t_deque q;

    init_deque(&q);
    printf("# ADD FRONT\n\n");
    for (int i = 0; i < 3; i++) {
        add_front(&q, i);
        print_deque(&q);
    }

    printf("\n# DELETE REAR\n\n");
    for (int i = 0; i < 3; i++) {
        delete_rear(&q);
        print_deque(&q);
    }

    printf("\n# ADD REAR\n\n");
    for (int i = 0; i < 3; i++) {
        add_rear(&q, i);
        print_deque(&q);
    }

    printf("\n# DELETE FRONT\n\n");
    for (int i = 0; i < 3; i++) {
        delete_front(&q);
        print_deque(&q);
    }

    free(q.data);
    return 0;
}