#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createList(){
    if (head == NULL)
        printf("List created.\n");
    else
        printf("List already exist.\n");
}

void displayList(){
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("\nList: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void addToFirst(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at first.\n", data);
}

void addToLast(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        printf("Inserted %d at last (list was empty).\n", data);
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next; 
    }

    temp->next = newNode;
    printf("Inserted %d at last.\n", data);
}

void addAtPos(int data, int pos){
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    
    if (pos == 1){
        addToFirst(data);
        return;
    }
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    
    struct Node* temp = head;
    int counter = 1;

    while(temp != NULL && counter < pos - 1){
        temp = temp->next;
        counter++;
    }

    if(temp == NULL){
        printf("Position %d is out of bounds.\n", pos);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", data, pos);
}

int main() {
    int choice, data, position;

    do {
        printf("\n\n--- Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Add to First\n");
        printf("3. Add to Last\n");
        printf("4. Add at Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                addToFirst(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                addToLast(data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position (1-based): ");
                scanf("%d", &position);
                addAtPos(data, position);
                break;
            case 5:
                displayList();
                break;
            case 6:
                printf("Exiting program and freeing memory.\n");
                struct Node *current = head;
                struct Node *next_node;
                while (current != NULL) {
                    next_node = current->next;
                    free(current);
                    current = next_node;
                }
                head = NULL;
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}