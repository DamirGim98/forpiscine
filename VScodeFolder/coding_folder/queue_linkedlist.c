#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data; 
    struct Node * link;
    struct Node * prev;  
};

void Enqueue (struct Node ** front, struct Node ** rear, int x)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    if (* front == NULL && * rear  == NULL)
    {
        temp->data = x;
        temp->link = NULL;
        temp->prev = NULL;
        * rear = temp;
        * front = temp;
        return;
    }
    temp->data = x;
    temp->link = * front;
    temp->prev = NULL;
    (*front)->prev = temp; 
    * front = temp;
}

void Print(struct Node* head)
{
    printf("List is:");
    while (head != NULL)
    {
        printf(" %d", head->data);
        head = head->link; 
    }
    printf("\n");
}

int  Dequeue (struct Node ** rear)
{
    if (*rear == NULL)
    {
        printf("Nothing to dequeue!");
        return 0;
    }
    else
    {
        struct Node * temp = (*rear)->prev;
        temp->link = NULL;
        temp = *rear;
        int x = (*rear)->data;
        *rear = (* rear)->prev;
        free(temp);
        return (x);
    }
}

void Printrev(struct Node* head)
{
    printf("List is:");
    while (head->link != NULL)
    {
        head = head->link; 
    }
    while (head != NULL)
    {
        printf(" %d", head->data);
        head = head->prev;
    }
    printf("\n");
}

int main(void)
{
    struct Node * head = NULL;
    struct Node * rear = NULL;
    int n = 10,x; 
    for (int i = 0; i < n; i++)
    {
        Enqueue(&head,&rear,i);
    }
    Print(head);
    Dequeue(&rear);
    Dequeue(&rear);
    Dequeue(&rear);
    Print(head);
    return 0;
}