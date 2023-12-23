#ifndef CUSTOMERQUEUE_QUEUE_H
#define CUSTOMERQUEUE_QUEUE_H

typedef struct Customer {
    char name[50];
    int customerNumber;
    struct Customer *next;
} Customer;

typedef struct Queue {
    Customer *front;
    Customer *rear;
} Queue;

Queue *create();

void init(Queue *queue);

/*
 * return 1 : Queue is empty
 * return 0 : Queue is not empty
 */
int isEmpty(Queue *queue);

Customer *createNode(char *name, int customerNr);

void enqueue(Queue *queue, Customer *node);

void dequeue(Queue *queue);

void front(Queue *queue);

void size(Queue *queue);

void printQueue(Queue *queue);

//void peek(Queue *queue);
//void rear(Queue *queue);


#endif //CUSTOMERQUEUE_QUEUE_H
