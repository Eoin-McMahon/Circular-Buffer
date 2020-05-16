#include "cu/cu.h"
#include <stdio.h>
#include "../circularBuffer.h"

// Make sure enqueue is successfull
TEST(test1) {
    queue_t * circular_buffer = malloc(sizeof(queue_t));  
    init(circular_buffer);
    assertEquals(enqueue(circular_buffer, 1), 0);
    free(circular_buffer);
}

// Make sure dequeue is successfull
TEST(test2) {
    queue_t * circular_buffer = malloc(sizeof(queue_t));  
    init(circular_buffer); 
    int * value = malloc(sizeof(int));   
    assertEquals(enqueue(circular_buffer, 1), 0);
    assertEquals(dequeue(circular_buffer, value), 0);
    free(circular_buffer);
    free(value);
}

// check that queue capacity functions
TEST(test3) {
    queue_t * circular_buffer = malloc(sizeof(queue_t));  
    init(circular_buffer);
    enqueue(circular_buffer, 1);
    enqueue(circular_buffer, 2);
    enqueue(circular_buffer, 3);
    enqueue(circular_buffer, 4);
    assertEquals(circular_buffer->size, QUEUE_SIZE);
    free(circular_buffer);
}

// make sure that queue is empty
TEST(test4) {
    queue_t * circular_buffer = malloc(sizeof(queue_t));  
    init(circular_buffer);
    int* value = malloc(sizeof(int));   
    enqueue(circular_buffer, 1);
    dequeue(circular_buffer, value);
    assertEquals(circular_buffer->size, QUEUE_SIZE);
    free(circular_buffer);
    free(value);
}

// make sure that enqueue works properly when the queue is full
TEST(test5) {
    queue_t * circular_buffer = malloc(sizeof(queue_t));  
    init(circular_buffer);
    enqueue(circular_buffer, 1);
    enqueue(circular_buffer, 2);
    enqueue(circular_buffer, 3);
    enqueue(circular_buffer, 4);
    enqueue(circular_buffer, 5);    // This will not be added as the queue is full
    assertEquals(circular_buffer->count, QUEUE_SIZE);
    free(circular_buffer);
}

TEST(test6) {
    queue_t * circular_buffer = malloc(sizeof(queue_t));  
    init(circular_buffer);
    int* value = malloc(sizeof(int));   
    enqueue(circular_buffer, 1);
    dequeue(circular_buffer, value);    // This is fine
    dequeue(circular_buffer, value);    // This is not, since the queue is already empty
    assertEquals(circular_buffer->count, 0);
    free(circular_buffer);
    free(value);
}

