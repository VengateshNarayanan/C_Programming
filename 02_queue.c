        #include <stdio.h>
        #define MAX 5
        int queue[MAX];
        int front = -1;
        int rear = -1;
        /* Function to insert an element into the queue */
        void enqueue()
        {
        int value;
        if (rear == MAX - 1)
        {
        printf("\nQueue Overflow! Queue is full.");
        }
        else
        {
        printf("\nEnter the element to insert: ");
        scanf("%d", &value);
        if (front == -1)
        front = 0;
        rear++;
        queue[rear] = value;
        printf("\n%d inserted into the queue.", value);
        }
        }
        /* Function to delete an element from the queue */
        void dequeue()
        {
        if (front == -1 || front > rear)
        {
        printf("\nQueue Underflow! Queue is empty.");
        }
        else
        {
        printf("\n%d deleted from the queue.", queue[front]);
        front++;
        if (front > rear)
        {
        front = -1;
        rear = -1;
        }
        }
        }
        /* Function to display queue elements */
        void display()
        {
        int i;
        if (front == -1)
        {
        printf("\nQueue is empty.");
        }
        else
        {
        printf("\nElements in the queue are: ");
        for (i = front; i <= rear; i++)
        {
        printf("%d ", queue[i]);
        }
        }
        }
        /* Main function */
        void main()
        {
        int choice;
        do
        {
        printf("\n\n--- QUEUE ADT USING ARRAY ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        enqueue();
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        case 4:
        printf("\nExiting program...");
        break;
        default:
        printf("\nInvalid choice!");
        }
        } while (choice != 4);

        
        }