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

    fflush(stdin);
    printf("Enter name: ");
    gets(name);

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
    //sorting_alpha();
    
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
void sorting_alpha() {
    if (head == NULL) {
        printf("\nNo data to sort!\n");
        return;
    }
    struct node *i, *j;
    char tempName[50];
    int tempRoll;
    float tempPercentage;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) > 0) {
                strcpy(tempName, i->name);
                tempRoll = i->roll;
                tempPercentage = i->per;
                strcpy(i->name, j->name);
                i->roll = j->roll;
                i->per = j->per;
                strcpy(j->name, tempName);
                j->roll = tempRoll;
                j->per = tempPercentage;
            }
        }
    }
    printf("\nData sorted successfully!\n");
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

/*void writedata(){
	struct node *ptr;
	ptr=head;
	FILE *fp=fopen("student.doc","w");
	while(ptr!=NULL){
		fwrite(ptr,sizeof(struct node),1,fp);
		ptr=ptr->next;
	}
	fclose(fp);
	printf("Data is written to the file successfully.\n");
}
void readdata(struct node *h){
	struct node *newNode = (struct node *)malloc(sizeof(struct node)); 
	struct node s1;
	FILE *fp=fopen("student.doc","r");
	
	strcpy(newNode->name, s1.name);
    newNode->per = s1.per;
    newNode->next = newNode->prev = NULL;

	while(fread(&s1,sizeof(struct node),1,fp));{
	if (h == NULL)
    {
        h = newNode;
        head=h;
        return;
    }
    else
    {
        newNode->next = head;
        h->prev = newNode;
        h = newNode;
        head=h;
    }
	
	}
	fclose(fp);
}
*/
int main()
{
    int choice;
    while (1)
    {
        system("cls");
        printf("\nChoose an option:\n");
        printf("1. Add a student to the list\n");
        printf("2. Display the list of students\n");
        printf("3. Delete a student from the list\n");
        printf("4. Print the total no of the students:\n");
        printf("5. Write to file:\n");
        printf("6. Read from file and write to linked list\n");
        printf("7. Exit the program\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            sorting_alpha();
            break;
        case 2:
            
			display();
            getch();
            break;
        case 3:
           del_pos();
           getch();
            break;
        case 4:
            printf("The total number of the students is %d\n", count());
            break;
        /*case 5:
        	writedata();
        	getch();
        	break;
        case 6:
			readdata(head);
			break;*/
		case 7:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
