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
    init(queue);
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

Customer *createNode(char *firstname, char *lastname, int customerNr) {
    Customer *new = (Customer *) malloc(sizeof(Customer));
    if (new == NULL) {
        printf("Memory allocation failure\n");
        return NULL;
    }
    strcpy(new->firstName, firstname);
    strcpy(new->lastName, lastname);
    new->customerNumber = customerNr;
    new->next = NULL;
    return new;
}

/*
 * Customer *node : node to add
 * return 0: enqueue success
 * return -1: enqueue failed
 */
int enqueue(Queue *queue, Customer *node) {
    if (queue == NULL) {
        printf("Error: Queue is NULL\n");
        return -1;
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
    return 0;
};

/* Find the previous node of the node that matches the entered information. */
Customer *findPreNode(Queue *queue, char *firstName, char *lastName) {
    // Validation
    if (queue == NULL || isEmpty(queue)) {
        printf("Error: Queue is NULL or empty\n");
        return NULL;
    }
    // If first node matches
    if (queue->front->firstName == firstName && queue->front->lastName == lastName) {
        return queue->front;
    }
    // Search from second node
    Customer *current = queue->front->next;
    while (current != NULL) {
        if (strcmp(current->firstName, firstName) == 0 && strcmp(current->lastName, lastName) == 0) {
            return current;
        }
        current = current->next;
    }
    // Unable to find previous node
    return NULL;
};

int dequeue(Queue *queue) {
    if (queue == NULL || isEmpty(queue)) {
        printf("Error: Queue is NULL or empty\n");
        return -1;
    }
    Customer *toDequeue = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(toDequeue);
    return 0;
}



/*
 * Customer *preNode: previous node to delete
 * Customer *node : node to delete
 * return 0: dequeue success
 * return -1: dequeue failed
 */
//int dequeue(Queue *queue, Customer *preNode, Customer *node) {
//    if (queue == NULL || preNode == NULL || node == NULL) {
//        printf("Error: Queue or Node is NULL\n");
//        return -1;
//    } else if (isEmpty(queue)) {
//        printf("Queue is empty\n");
//        return -1;
//    } else {
//        // Remove node from the queue and free them
//        preNode->next = node->next;
//        free(node);
//        return 0;
//    }
//};

Customer *front(Queue *queue) {
    if (queue == NULL) {
        printf("Error: Queue is NULL\n");
        return NULL;
    } else if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    } else {
        return queue->front;
    }
};

int size(Queue *queue) {
    int count = 0;
    if (queue == NULL) {
        printf("Error: Queue is NULL\n");
        return -1;
    } else if (!isEmpty(queue)) {
        Customer *current = queue->front;
        while (current != NULL) {
            count++;
            current = current->next;
        }
    }
    return count;
};

void printNode(Customer *node) {
    if (node == NULL) {
        return;
    }
    printf("Customer Number: %d\n", node->customerNumber);
    printf("Customer Name: %s %s\n", node->firstName, node->lastName);
    printf("------------------------------------\n");
};

void printQueue(Queue *queue) {
    if (queue == NULL) {
        printf("Error: Queue is NULL\n");
        return;
    } else if (!isEmpty(queue)) {
        Customer *current = queue->front;
        while (current != NULL) {
            printNode(current);
            current = current->next;
        }
    }
};
