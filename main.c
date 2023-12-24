#include "queue.h"
#include "random.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    Queue *myQueue = create();

    if (myQueue == NULL) {
        printf("Error: Queue is NULL\n");
        return -1;
    }

    int code = -1;
    int result = 0;
    int customerNr = 20030000;
    do {
        char firstName[50];
        char lastName[50];

        printf("=======================\n");
        printf("1: Add Customer\n");
        printf("2: Remove Customer\n");
        printf("3: Read First Customer\n");
        printf("4: Get Queue Size\n");
        printf("5: Print Queue\n");
        printf("6: Enqueue 10 random customers\n");
        printf("=======================\n");
        printf("0: Program end \n");
        scanf("%d", &code);

        if (code < 0 || code > 6) {
            printf("Input wrong\n");
            continue; // Go to the start
        }

        Customer *customer;
        switch (code) {
            case 1:
                // Get values from the console
                printf("Firstname:");
                scanf("%s", firstName);
                printf("Lastname:");
                scanf("%s", lastName);

                // Create customer
                customer = createNode(firstName, lastName, ++customerNr);
                if (customer == NULL) {
                    printf("Error: Unable to create customer.\n");
                    break;
                }
                // Add customer to the queue
                result = enqueue(myQueue, customer);
                if (result == -1) {
                    printf("Error: Unable to add customer.\n");
                } else {
                    printf("Customer added successfully.\n");
                }
                break;
            case 2:
                result = dequeue(myQueue);
                if (result == -1) {
                    printf("Error: Unable to delete customer.\n");
                } else {
                    printf("Customer deleted successfully.\n");
                }
                break;
            case 3:
                customer = front(myQueue);
                if (customer != NULL) {
                    printNode(customer);
                }
                break;
            case 4:
                result = size(myQueue);
                if (result > 0) {
                    printf("Queue Size: %d\n", result);
                }
                break;
            case 5:
                printQueue(myQueue);
                break;
            case 6:
                // Initialize the random number generator
                srand((unsigned int) time(NULL));
                for (int i = 0; i < 10; i++) {
                    generateRandomName(firstName, 6);
                    generateRandomName(lastName, 4);
                    customer = createNode(firstName, lastName, ++customerNr);
                    if (customer != NULL) {
                        enqueue(myQueue, customer);
                    }
                }
                printf("Success: Enqueue 10 random customers\n");
            default:
                break;
        }
    } while (code != 0);
    return 0;
}