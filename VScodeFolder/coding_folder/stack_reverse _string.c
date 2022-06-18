#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data; 
    struct Node* link; 
};

void Push (char x, struct Node ** ptr)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = *ptr; 
    * ptr = temp;
}

void Pop (struct Node ** ptr)
{
    struct Node * temp = * ptr; 
    if (* ptr == NULL) printf("Nothing to pop");
    else 
    {
        * ptr = (*ptr)->link;
        free(temp);
    }
}

int IsEmpty (struct Node * ptr)
{
    int a = 1;
    if (ptr != NULL) a =0;
    return a;
}

void Print(struct Node* ptr) 
{
    printf("This is the stack:\n");
    struct Node * temp = ptr;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void ReverseStr(char C[], int n, struct Node ** ptr)
{
    for (int i = 0; i<n; i++)
    {
        Push(C[i], ptr);
    }
}


int main()
{

    struct Node * top = NULL; 
    printf("Enter the string pls");
    char S[100];
    fgets(S,sizeof(S),stdin);
    fflush(stdin);
    int n = strlen(S);
    ReverseStr(S,n,&top);
    Print(&top);
    // printf("%s\n", S);
}
