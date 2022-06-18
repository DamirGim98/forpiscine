#include <stdio.h>
# define MAX_SIZE 101

void Push(int x, int * top, int * A)
{
    if (*top == MAX_SIZE -1)
    {
        printf("Error: overflow stack\n");
    } else 
    {
        * top = *top + 1;
        A[*top] = x; 
    }
}

void Pop(int * top)
{
    if (*top == -1)
    {
        printf("Error: No element to pop\n");
    }
    * top = *top - 1;
}

void top();

void Print(int * top, int * A)
{
    int i = 0; 
    printf("Stack:\n");
    for (;i<= *top; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}


int main()
{
    int A[MAX_SIZE];
    int top = -1;
    Push(2,&top, A); Print(&top, A);
    Push(3,&top, A); Print(&top, A);
    Push(4,&top, A); Print(&top, A);
    Push(5,&top, A); Print(&top, A);
    
}