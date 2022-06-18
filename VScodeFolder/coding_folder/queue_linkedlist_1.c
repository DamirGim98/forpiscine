#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data; 
    struct Node * link;
};

void Enqueue (struct Node ** front, struct Node ** rear, int x)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = NULL;
    if (* front == NULL && * rear  == NULL)
    {
        * rear = temp;
        * front = temp;
        return;
    }
    (*rear)->link = temp;
    *rear = temp;
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

int Dequeue (struct Node ** front, struct Node ** rear)
{
    int x = 0;
    struct Node * temp = * front;
    if (*front == NULL)
    {
        printf("Nothing to dequeue!");
    }
    if (* front == * rear)
    {
        *front = NULL;
        *rear = NULL;
    } else 
    {
        x = (*front)->data;
        *front = (*front)->link;
        free(temp);
    }
    return x;
}

// void Printrev(struct Node* head)
// {
//     printf("List is:");
//     while (head->link != NULL)
//     {
//         head = head->link; 
//     }
//     while (head != NULL)
//     {
//         printf(" %d", head->data);
//         head = head->prev;
//     }
//     printf("\n");
// }

int main(void)
{
    struct Node * head = NULL;
    struct Node * rear = NULL;
    int n = 3,x; 
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        Enqueue(&head,&rear,x);
    }
    Print(head);
    Dequeue(&head,&rear);
    Print(head);
    return 0;
}