#include "queue.h"

#include<stdio.h>
#include<stdlib.h>

int main(){
    QUEUE *queue = queue_generate();
    queue_push(queue, 1);
    queue_push(queue, 5);
    queue_pop(queue);
    queue_push(queue, 3);
    queue_print(queue);
    queue_push(queue, 6);
    queue_push(queue, 4);
    queue_pop(queue);
    queue_push(queue, 2);
    queue_print(queue);
}