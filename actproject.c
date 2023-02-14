#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int roll;
    char name[20];
    float per;
    struct node *prev; // points towards prev
    struct node *next; // points toward next
};
struct node *head = NULL;
void create()
{
    int roll;
    char name[20];
    float a, b, c, d, e;
    float per;
    printf("Enter name: ");
    scanf("%s", &name);
    printf("Enter roll: ");
    scanf("%d", &roll);
    printf("Enter percentage ");
    scanf("%f", &per);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    strcpy(newNode->name, name);
    newNode->roll = roll;
    newNode->per = per;
    newNode->next = newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nThe list is empty\n");
        return;
    }
    else
    {
printf("Name\tRoll No.\tPercentage\n");
        while (ptr != NULL)
        {
           printf("%s\t%d\t\t%.2f%%\n", ptr->name, ptr->roll, ptr->per);
           ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    do
    {
        printf("enter 1 to create list\n");
        printf("enter 2 to display list\n");
        printf("enter 0 to exit list\n");
        printf("enter choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display(head);
            break;
            // case 0:
            //   printf("exitted");
            // break;
        }
    } while (choice != 0);
}

