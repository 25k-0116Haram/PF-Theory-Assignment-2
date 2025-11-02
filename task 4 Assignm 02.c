#include <stdio.h>

void push(int stack[], int *top, int maxSize);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main() {
    int stack[100];
    int top = -1;
    int maxSize;
    int choice;

    printf("Enter maximum size of stack: ");
    scanf("%d", &maxSize);

    do {
        printf("\n===== STACK OPERATIONS MENU =====\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push(stack, &top, maxSize);
                break;

            case 2:
                pop(stack, &top);
                break;

            case 3:
                peek(stack, top);
                break;

            case 4:
                display(stack, top);
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 5);

    return 0;
}

// Function to insert (PUSH) an element into the stack
void push(int stack[], int *top, int maxSize) {
    int value;

    if (*top == maxSize - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d", &value);

    (*top)++;
    stack[*top] = value;

    printf("Value %d pushed into stack successfully.\n", value);
}

// Function to remove (POP) the top element from the stack
void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }

    printf("Popped element: %d\n", stack[*top]);
    (*top)--;
}

// Function to display the top element (PEEK)
void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

// Function to display all elements in the stack
void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Current stack elements (top to bottom):\n");
	int i;
    for ( i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

