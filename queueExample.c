#include "circularBuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    queue_t * circular_buffer = malloc(sizeof(queue_t));  
    init(circular_buffer);
    enqueue(circular_buffer, 1);
    enqueue(circular_buffer, 2);
    enqueue(circular_buffer, 3);
    enqueue(circular_buffer, 4);
    enqueue(circular_buffer, 5);       // Queue is full
    int* value = malloc(sizeof(int));   
    dequeue(circular_buffer, value);
    dequeue(circular_buffer, value);
    dequeue(circular_buffer, value);
    dequeue(circular_buffer, value);
    dequeue(circular_buffer, value);   // Queue is empty
    free(circular_buffer);
    free(value);
}