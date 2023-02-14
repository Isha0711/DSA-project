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
    
	fflush(stdin);
    printf("Enter name: ");
    gets(name);
    
	printf("Enter roll: ");
    scanf("%d", &roll);
    printf("Enter marks of 5 subjects ");
    scanf("%f%f%f%f%f", &a, &b, &e, &d, &e);
    per = ((a + b + c + d + e) / 500) * 100;
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
        printf("Name\t\tRoll No.\tPercentage\n");
        while (ptr != NULL)
        {
            printf("%s\t%d\t\t%.2f%%\n", ptr->name, ptr->roll, ptr->per);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

    
    void del_pos(){
    	   int pos;
    struct node *ptr;
    int i;
    printf("enter position:");
    scanf("%d", &pos);
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) {
        ptr=head;
		head = ptr->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(ptr);
        printf("Node at position %d deleted successfully!\n", pos);
        return;
    }
    
    for (i = 1; i < pos; i++) {
        ptr=head;
		ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Position %d out of range!\n", pos);
        return;
    }
    ptr->prev->next = ptr->next;
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    printf("Node at position %d deleted successfully!\n", pos);
}



int main() {
    int choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add a student to the list\n");
        printf("2. Display the list of students\n");
        printf("3. Delete a student from the list\n");
        printf("4. Exit the program\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
              
                del_pos();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
