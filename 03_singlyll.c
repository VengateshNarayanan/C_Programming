#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL , *temp , *newnode , *prev;

// Inserting the element at the end 

void create()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d" , &newnode->data);
    newnode->next  = NULL;
    if(head==NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Inserting the elements at the beginning 
void insertbeg()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d" , &newnode->data);
    newnode->next = head;
    head = newnode;

}

//inserting the element at the end

void insertend()
{
    create();
}

// deleting the element form the beginning

void deletebeg()
{
    if(head == NULL)
    {
        printf("list is empty. \n");
        return;
    }
    temp = head;
    head = head->next;
    printf("deleted element = %d\n" , temp->data);
    free(temp);

}
// deleting from end

void deleteend()
{
    if(head==NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if(head->next == NULL)
    {
        printf("deleted element = %d\n" , head->data);
        free(head);
        head = NULL;
        return;

    }
    temp = head;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;

    }
    prev->next = NULL;
    printf("deleted element = %d\n" , temp->data);
    free(temp);


}

void display()
{
    if(head == NULL)
    {
        printf("list is empty.\n");
        return;

    }
    temp = head;
    printf("linked list: ");
    while (temp != NULL)
    {
        printf("%d->" , temp->data);
        temp = temp->next;

    }
    printf("NULL\n");

}


// Main Function
void main(){

    int choice;
    while(1)
    {
        printf("\n----Singly Linked List------\n");
        printf("Enter 1 to create(insert at end)\n");
        printf("Enter 2 to insert at beginning\n");
        printf("Enter 3 to insert at end\n");
        printf("Enter 4 to delete from beginning\n");
        printf("Enter 5 to delete from end\n");
        printf("Enter 6 to display\n");
        printf("Enter 7 to exit\n");

        printf("Enter your choice: ");
        scanf("%d" , &choice);
        switch(choice){
            case 1:
            create();
            break;

            case 2:
            insertbeg();
            break;

            case 3:
            insertend();
            break;

            case 4:
            deletebeg();
            break;

            case 5:
            deleteend();
            break;

            case 6:
            display();
            break;

            case 7:
            exit(0);
            break;

            default:
            printf("Invalid Choice!\n");


        }
    }
}