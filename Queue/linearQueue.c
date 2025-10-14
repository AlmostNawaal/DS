#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

int Q[SIZE];

int front = -1;
int rear = -1;

int isFull(){
    if (rear == SIZE - 1){
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
        printf("Overflow! Queue is full.\n");
        return 0;
    }
    else if(isEmpty()){
        front = 0;
        rear = 0;
        Q[rear] = x;
    }
    else{
        rear++;
        Q[rear] = x;
    }
    return 1;
}

int dequeue() {
    int data;

    if (isEmpty()) {
        printf("Underflow! Queue is empty.\n");
        return -1;
    }
    else if (front == rear) {
        data = Q[front];
        front = -1;
        rear = -1;
    }
    else {
        data = Q[front];
        front++;
    }
    return data;
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}

int main(){
    int ch;
    while(true){
        printf("options:\n\n1.Push\n2.Pop\n3.Display\n4.exit\n");
        printf("Enter your choice: ");

        scanf("%d",&ch);

        switch(ch){
            case 1:{
                int x;
                printf("enter the element:");
                scanf("%d",&x);
                enqueue(x);
                break;
            }
            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid option.\n");
                break;
        }
    }
}
