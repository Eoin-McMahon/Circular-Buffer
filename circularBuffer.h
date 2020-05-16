#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Status Codes
#define SUCCESS 0
#define QUEUE_IS_NULL -1
#define QUEUE_IS_EMPTY 1
#define QUEUE_IS_FULL 2
#define QUEUE_SIZE 4

struct queue {
    int* buffer;    // array to hold the data for the queue
    int* head;      // pointer to the haed of the queue
    int* tail;      // pointer to the tail of the queue
    int count;      // number of items in the queue 
    size_t size;    // max number of items in the queue
};

typedef struct queue queue_t;

bool is_full(queue_t* q);
bool is_empty(queue_t* q);
bool is_null(queue_t* q);
void init(queue_t* q);
int enqueue(queue_t* q, int val);
int dequeue(queue_t* q, int *val);

// initialise the circular queue
void init(queue_t* q) {
    q->buffer = malloc(sizeof(int) * QUEUE_SIZE);
    q->size = QUEUE_SIZE;
    q->head = q->buffer;
    q->tail = q->buffer;
    q->count = 0;
}

// add an item to the queue
int enqueue(queue_t* q, int val) {
    if (is_null(q)) {
        printf("ERROR: Cannot add to the queue - QUEUE IS NULL\n");
        return QUEUE_IS_NULL;
    }
    if(is_full(q)) {
        printf("ERROR: Cannot add %d to the queue - QUEUE IS FULL\n", val);
        return QUEUE_IS_FULL;
    }

    // set value at tail to new value and advance the tail pointer
    *q->tail = val;
    q->tail++;

    // if we arrive at the end - wrap around
    if (q->tail == q->buffer + QUEUE_SIZE) {
        q->tail = q->buffer;
    }
    q->count++;
    printf("SUCCESSFULLY QUEUED VALUE: %d\nNEW ITEM COUNT: %d\n\n", val, q->count);

    return SUCCESS;
}

// point val to dequeued item and advance head so it can be overwritten
int dequeue(queue_t* q, int * val) {
    if (is_null(q)) {
        printf("ERROR: Cannot add to the queue - QUEUE IS NULL\n");
        return QUEUE_IS_NULL;
    }
    if (is_empty(q)) {
        printf("ERROR: Cannot remove from the queue - QUEUE IS EMPTY\n");
        return QUEUE_IS_EMPTY;
    }
    // store value that we are dequeing and advance the head pointer
    *val = *q->head;
    q->head++;

    // if we are at the end of the queue - wrap around
    if (q->head == q->buffer + QUEUE_SIZE) {
        q->head = q->buffer;
    }
    q->count--;
    printf("SUCCESSFULLY DEQUEUED VALUE: %d\nNEW ITEM COUNT: %d\n\n", *val, q->count);

    return SUCCESS;
}

void free_the_buffer(queue_t * q) {
    free(q->buffer);
}

// check if the queue is full
bool is_full(queue_t* q) {
    return q->count == q->size;
}

// check if the queue is empty
bool is_empty(queue_t* q) {
    return q->count == 0;
}

// check if the queue is null
bool is_null(queue_t* q) {
    return q == NULL || q->buffer == NULL;
}
