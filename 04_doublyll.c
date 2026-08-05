#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*prev;
    struct Node*next;

};

struct Node*head = NULL;

// create a new node 
struct Node* createNode(int value)
{
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;

}

// insert at beginning

void insertbeginning(int value)
{
    struct Node*newNode = createNode(value);
    if(head == NULL)
    {
        head = newNode;

    }
    
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;

    }

    printf("%d inserted at beginning\n " , value);



}


// insert at end 

void insertend(int value)
{
    struct Node*newNode = createNode(value);
    if(head==NULL)
    {
        head = newNode;

    }

    else
    {
        struct Node*temp = head;

        while(temp->next!=NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;

    }

    printf("%d inserted at end.\n" , value);

}

// Delete from beginning
void deletebeginning()
{
    if(head==NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node*temp = head;

    if(head->next==NULL)
    {
        head=NULL;
    }
    else
    {
        head = head->next;
        head->prev=NULL;

    }
    printf("%d deleted from beginning.\n" , temp->data);
    free(temp);
}
//delete from end
void deleteend()
{
    if(head==NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node*temp = head;
    if(head->next==NULL)
    {
        printf("%d deleted from end.\n" , head->data);
        free(head);
        head=NULL;
        return;
    }

    while(temp->next!=NULL)
    {
        temp = temp->next;

    }

    temp->prev->next = NULL;

    printf("%d deleted from end\n" , temp->data);
    free(temp);


    
}

void displayforward()
{
    if(head == NULL)
    {
        printf("list is empty.\n");
        return;
    }

    struct Node*temp = head;

    printf("list(forward):");

    while(temp != NULL)
    {
        printf("%d" , temp->data);
        temp = temp->next;

    }
    printf("\n");
}

void displayreverse()
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct Node*temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    printf("List(reverse):");

    while(temp!=NULL)
    {
        printf("%d" , temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main Function
    int main()
    {
    int choice, value;
    while(1)
    {

        printf("\n===== Doubly Linked List Menu =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display Forward\n");
        printf("6. Display Reverse\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        printf("Enter value: ");
        scanf("%d", &value);
        insertbeginning(value);
        break;

        case 2:
        printf("Enter value: ");
        scanf("%d", &value);
        insertend(value);
        break;

        case 3:
        deletebeginning();
        break;

        case 4:
        deleteend();
        break;

        case 5:
        displayforward();
        break;

        case 6:
        displayreverse();
        break;

        case 7:

        printf("Exiting...\n");
        exit(0);
        default:
        printf("Invalid Choice!\n");
    }
    }
         return 0;
    }