#ifndef CUSTOMERQUEUE_QUEUE_H
#define CUSTOMERQUEUE_QUEUE_H

typedef struct Customer {
    char firstName[50];
    char lastName[50];
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

Customer *createNode(char *firstname, char *lastname, int customerNr);

/*
 * @param Customer *node : node to add
 * return 0: enqueue success
 * return -1: enqueue failed
 */
int enqueue(Queue *queue, Customer *node);

/* Find the previous node of the node that matches the entered information. */
Customer *findPreNode(Queue *queue, char *firstName, char *lastName);

/*
 * @param Customer *preNode: previous node of node to delete
 * @param Customer *node: node to delete
 * return 0: dequeue success
 * return -1: dequeue failed
 */
int dequeue(Queue *queue, Customer *preNode, Customer *node);

Customer *front(Queue *queue);

int size(Queue *queue);

void printNode(Customer *node);

void printQueue(Queue *queue);

//void peek(Queue *queue);
//void rear(Queue *queue);


#endif //CUSTOMERQUEUE_QUEUE_H
