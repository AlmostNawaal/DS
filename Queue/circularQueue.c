#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

int Q[SIZE];

int front = -1;
int rear = -1;

int isFull(){
    if ((rear + 1) % SIZE == front) {
        return 1;
    }
    return 0;
}


int isEmpty(){
    if (front == -1 && rear == -1){
        return 1;
    }
    return 0;
}

int enqueue(int x){
    if (isFull()){
        printf("Overflow! Circular Queue is full.\n");
        return 0;
    }
    else if(isEmpty()){
        front = 0;
        rear = 0;
    }
    else{
        rear = (rear + 1) % SIZE;
    }

    Q[rear] = x;
    return 1;
}

int dequeue() {
    int data;

    if (isEmpty()) {
        printf("Underflow! Circular Queue is empty.\n");
        return -1;
    }

    data = Q[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % SIZE;
    }

    return data;
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Circular Queue is empty.\n");
    } else {
        printf("Circular Queue elements are: ");
        i = front;
        while(true) {
            printf("%d ", Q[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
        printf("Front: %d, Rear: %d\n", front, rear);
    }
}

int main(){
    int ch;
    while(true){
        printf("\n--- Circular Queue Operations ---\n");
        printf("options:\n\n1. Enqueue (Push)\n2. Dequeue (Pop)\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d",&ch) != 1) {
            printf("Invalid input. Exiting.\n");
            return 1;
        }

        switch(ch){
            case 1:{
                int x;
                printf("Enter the element to enqueue: ");
                if (scanf("%d",&x) != 1) {
                    printf("Invalid element input.\n");
                    while (getchar() != '\n');
                    break;
                }
                enqueue(x);
                break;
            }
            case 2:{
                int dequeued_val = dequeue();
                if (dequeued_val != -1) {
                    printf("Dequeued element: %d\n", dequeued_val);
                }
                break;
            }

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid option. Please choose between 1 and 4.\n");
                break;
        }
    }
}
