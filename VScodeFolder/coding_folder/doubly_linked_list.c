#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data; 
    struct Node * link;
    struct Node * prev; 
};

struct Node * GetNewNode(int x)
{
    struct Node *  newNode = (struct Node *)malloc(sizeof(struct Node)); 
    newNode->data = x; 
    newNode->link = NULL;
    newNode->prev = NULL; 
    return newNode;
} 
void InsertAtHead(struct Node ** ptr, int x)
{
    struct Node * newNode = GetNewNode(x); 
    if (* ptr == NULL)
    {
        * ptr = newNode;  
    } else 
    {
        (*ptr)->prev = newNode; 
        newNode->link = (*ptr); 
        (*ptr)= newNode;
    }
} 
void InsertAtTail(struct Node ** ptr, int x)
{
    struct Node * temp1 = GetNewNode(x);
    if (*ptr == NULL)
    {
        *ptr = temp1;
    }
    else 
    {
        struct Node * step = * ptr;
        while (step->link != NULL)
        {
            step = step->link;
        }
        step->link = temp1; 
        temp1->prev = step;
    }
}

void Print(struct Node * ptr)
{
    struct Node * temp = ptr; 
    printf("forward direction"); 
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link; 
    }
    printf("\n");
}

void ReversePrint(struct Node *ptr)
{
    struct Node * temp = ptr;
    if (temp == NULL) printf("Empty list");
    else 
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        printf("Reverse:"); 
        while (temp != NULL)
        {
            printf("%d ", temp->data); 
            temp = temp->prev;
        }
        printf("\n");
    }
}

int main()
{
    struct Node * head = NULL;
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x; 
        scanf("%d", &x);
        InsertAtTail(&head, x);

    }
    Print(head);
    // ReversePrint(head);
} 