#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node * link; 
}; 

void Insert_at_n(struct Node** ptr, int data, int n)
{
    struct Node * temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data; 
    temp1->link = NULL;
    if (n == 1)
    {
        temp1->link = (*ptr);
        *ptr = temp1;
    } else 
    {
        struct Node * temp2 = (*ptr);
        for (int i = 0; i < n - 2; i++)
        {
            temp2 = temp2->link;
        }
        temp1->link = temp2->link;
        temp2->link = temp1;
    }
}

void Insert(struct Node** ptr, int data)
{
    struct Node * temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->link = NULL;
    if (*ptr == NULL)
    {
        *ptr = temp1;        
    } else 
    {
        struct Node * head = *ptr;
        while (head->link != NULL)
        {
            head = head->link;
        }
        head->link = temp1;
    }
}

void Print(struct Node* ptr)
{
    printf("This is the list:\n");
    struct Node * temp = ptr;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void Delete(struct Node** ptr, int value)
{
    struct Node * temp = *ptr;
    if (temp->data == value)
    {
        *ptr = temp->link;
        free(temp);
    } else 
    {
        struct Node * temp2 = temp->link;
        while (temp2->data != value)
        {
            temp = temp->link;
            temp2 = temp->link;
        }
        temp->link = temp2->link;
        free(temp2);
        
    }  
}

void Reverse (struct Node ** ptr)
{
    struct Node *prev,*current, *next;
    prev = NULL;
    current = * ptr; 
    while (current != NULL)
    {
        next = current->link; 
        current->link = prev; 
        prev = current; 
        current = next; 
    }
    * ptr = prev; 
}


int main(void)
{
    struct Node * head = NULL; 
    printf("Enter how many elemets?\n");
    int n,x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter number to insert\n"); 
        scanf("%d", &x); 
        Insert(&head, x); 
    }
    Print(head);
    printf("Please write new number and chose its position\n");
    scanf("%d %d", &x, &n); 
    Insert_at_n(&head, x,n);
    Print(head); 
    printf("Now lets delete some elements by its value, enter value\n"); 
    scanf("%d", &x);  
    Delete(&head,x); 
    Print(head); 
    Reverse(&head);
    Print(head); 
    return 0;
}