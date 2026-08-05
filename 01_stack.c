#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Function to push an element
void push()
{
    int item;

    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the element to be added into the stack: ");
        scanf("%d", &item);

        top++;
        stack[top] = item;

        printf("%d item pushed into the stack.\n", item);
    }
}

// Function to pop an element
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("The deleted item is %d\n", stack[top]);
        top--;
    }
}

// Function to peek the top element
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("The top element is %d\n", stack[top]);
    }
}

// Function to display stack
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n------------ STACK OPERATIONS ------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}