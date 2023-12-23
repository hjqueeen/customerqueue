#include "queue.h"
#include <stdio.h>
#include <time.h>

int main() {
    Queue *myQueue = create();
    init(myQueue);
    
    if (myQueue == NULL) {
        printf("Error: Queue is NULL\n");
        return -1;
    }

    int code = -1;
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
            break; // Go to the start
        }

        if (code == 1 || code ==2 || code == 3) {
            printf("Firstname:");
            scanf("%s", firstName);
            printf("Lastname:");
            scanf("%s", lastName);
        }
        Customer *new;
        int number;
        switch (code) {
            case 1:
               new = createNode(firstName, lastName,number  );
               if(new == NULL){
                   break;
               }
                enqueue(myQueue, new);
                break;

            case 2:
                break;

            case 3:
                break;

            case 2:
                break;

            case 2:
                break;
            default:
                break;
        }
    } while (code != 0);
    return 0;
}