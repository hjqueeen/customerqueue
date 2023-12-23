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



#endif //CUSTOMERQUEUE_QUEUE_H
