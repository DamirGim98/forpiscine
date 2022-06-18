#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int data;
    struct Node* link; 
};

struct Node* head;

void Insert(int data, int n)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data; 
    temp1->link = NULL;
    if (n == 1)
    {
        temp1->link = head;
        head = temp1;
        return; 
    }
    struct Node* temp2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->link;
    }
    temp1->link = temp2->link;
    temp2->link = temp1;

}
void Print()
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
    head = NULL;
    Insert(2,1);
    Insert(3,2);
    Insert(4,1);
    Insert(5,2);
    Print();
    return 0;
}
