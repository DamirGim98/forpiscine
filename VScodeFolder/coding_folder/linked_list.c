#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int data;
    struct Node* link; 
};

struct Node* Insert(struct Node* head, int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = head; 
    head = temp; 
    return head; 

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
        Print(head); 
        
    }


    return 0;
}
