#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int data;
    struct Node* link; 
};

struct Node* Insert(struct Node* head, int x)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = x; 
    temp1->link = NULL;
    if (head == NULL)
    {
        head = temp1;
        return head; 
    } else 
    {
        struct Node* ptr = head;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp1;
        return head;
    }   
}

void Print(struct Node * head)
{
    printf("List is:");
    while (head != NULL)
    {
        printf(" %d", head->data);
        head = head->link; 
    }
    printf("\n");
    
}

void Delete(struct Node * head, int n)
{
    struct Node * temp1 = head;
    if (n == 1)
    {
        head = temp1->link;
        free(temp1);
        return;
    } 
    int i; 
    for (i = 0; i < n - 2; i++)
    {
        temp1 = temp1->link;
    }
    struct Node * temp2 = temp1->link;
    temp1->link = temp2->link; 
    free(temp2);
}


int main(void)
{
    struct Node* head = NULL;
    printf("How many numbers\n"); 
    int n,i,x;
    scanf("%d", &n); 
    for (i = 0; i < n; i++)
    {
        printf("Enter the number \n");
        scanf("%d", &x);
        head = Insert(head,x); 
    }
    Print(head);
    int k; 
    printf("Enter position\n"); 
    scanf("%d", &k);
    Delete(head, k);
    Print(head); 
    return 0;
}

