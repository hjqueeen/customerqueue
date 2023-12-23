#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//typedef struct Customer {
//    char name[50];
//    int customerNumber;
//    struct Customer *next;
//} Customer;
//
//typedef struct Queue {
//    Customer *front;
//    Customer *rear;
//} Queue;

Queue *create() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failure\n");
        return NULL;
    }
    return queue;
}

void init(Queue *queue) {
    if (queue == NULL) {
        printf("Error: Queue is NULL\n");
        return;
    }
    queue->front = NULL;
    queue->rear = NULL;
};

int isEmpty(Queue *queue) {
    if (queue == NULL) {
        printf("Error: Queue is NULL\n");
        return -1;
    }
    if (queue->front == NULL && queue->rear == NULL) {
        // Queue is empty
        return 1;
    } else {
        // Queue is not empty
        return 0;
    }
};

Customer *createNode(char *name, int customerNr) {
    Customer *new = (Customer *) malloc(sizeof(Customer));
    if (new == NULL) {
        printf("Memory allocation failure\n");
        return NULL;
    }
    strcpy(new->name, name);
    new->customerNumber = customerNr;
    new->next = NULL;
    return new;
}

void enqueue(Queue *queue, Customer *node) {
    if (queue == NULL) {
        printf("Error: Queue is NULL\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    } else {
        // Add new element to the end of queue
        queue->rear->next = node;
        // Update rear of queue
        queue->rear = node;
    }
};

void dequeue(Queue *queue);

void front(Queue *queue);

void size(Queue *queue);

void printQueue(Queue *queue);