#include "queue.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    Queue *myQueue = create();
    init(myQueue);

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

        printf("1: Add Customer\n");
        printf("2: Remove Customer\n");
        printf("3: Read First Customer\n");
        printf("4: Get Queue Size\n");
        printf("5: Print Queue\n");
        printf("===================\n");
        printf("0: Program end \n");
        scanf("%d", &code);

        if (code < 0 || code > 5) {
            printf("Input wrong\n");
            continue; // Go to the start
        }
        // Get values from the console
        if (code == 1 || code == 2 || code == 3) {
            printf("Firstname:");
            scanf("%s", firstName);
            printf("Lastname:");
            scanf("%s", lastName);
        }
        Customer *customer;
        switch (code) {
            case 1:
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
                customer = findPreNode(myQueue, firstName, lastName);
                result = dequeue(myQueue, customer, customer->next);
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
                    printf("Queue Size: %d", result);
                }
                break;
            case 5:
                printQueue(myQueue);
                break;
            default:
                break;
        }
    } while (code != 0);
    return 0;
}