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
    char name[20];
    float a, b, c, d, e;
    float per;

    printf("Enter name: ");
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline character

    printf("Enter marks of 5 subjects ");
    scanf("%f%f%f%f%f", &a, &b, &c, &d, &e);
    per = (a + b + c + d + e) / 5;

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
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

void sorting_alpha()
{
    struct node *current, *prev, *temp;
    int i = 1;

    if (head == NULL)
    {
        return;
    }

    for (current = head->next; current != NULL; current = current->next)
    {
        temp = current;
        prev = current->prev;

        while (prev != NULL && strcmp(prev->name, current->name) > 0)
        {
            if (temp->next == prev)
            {
                temp->prev = prev->prev;
                if (prev->prev != NULL)
                {
                    prev->prev->next = temp;
                }
                prev->next = temp->next;
                if (temp->next != NULL)
                {
                    temp->next->prev = prev;
                }
                temp->next = prev;
                prev->prev = temp;
            }
            else
            {
                temp->prev = prev->prev;
                if (prev->prev != NULL)
                {
                    prev->prev->next = temp;
                }
                prev->next->prev = temp;
                temp->next = prev->next;
                temp->prev = prev->prev;
                prev->prev = temp;
                prev->next = current->next;
                current->next->prev = prev;
                prev->next = temp;
                temp->next->prev = prev;
            }

            prev = temp->prev;
        }
    }

    // Update the roll numbers
    for (current = head; current != NULL; current = current->next)
    {
        current->roll = i++;
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
        printf("Name\t\tRoll No.\tPercentage\n");
        while (ptr != NULL)
        {
            printf("%-20s%-10d%-10.2f%%\n", ptr->name, ptr->roll, ptr->per);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void del_pos()
{
    struct node *ptr = head;
    int i, pos;
    printf("enter the position");
    scanf("%d", &pos);
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (pos == 1)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(ptr);
        printf("Student deleted successfully.\n");
        return;
    }
    for (i = 1; i < pos && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Position not found.\n");
        return;
    }
    ptr->prev->next = ptr->next;
    if (ptr->next != NULL)
    {
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    printf("Student deleted successfully.\n");
}
int count()
{
    struct node *ptr;
    ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Add a student to the list\n");
        printf("2. Display the list of students\n");
        printf("3. Delete a student from the list\n");
        printf("4. Print the total no of the students:\n");
        printf("5. Exit the program\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            sorting_alpha();
            break;
        case 2:
            display();
            break;
        case 3:

            del_pos();
            break;
        case 4:
            printf("The total number of the students is %d\n", count());
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}