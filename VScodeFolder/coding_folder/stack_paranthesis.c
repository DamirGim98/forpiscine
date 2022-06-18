#include <stdio.h>
#include <string.h>
# define MAX_SIZE 101

void Push(char x, int * top, char * A)
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

char top(char * A, int top)
{
    return A[top];
}

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
    char A[MAX_SIZE];
    int top = -1;
    char opening[] = "{[(";
    char string[50];
    fgets(string, sizeof(string), stdin);
    int n = strlen(string);
    for (int i = 0; i < n; i++)
    {
        if (strchr(opening,string[i]))
        {
            Push(string[i],&top, A); 
        } else
        {
            if (top == -1 || A[top] != string[i])
            {
                printf("false\n");
                break;
            } else
            {
                Pop(&top);
            }
        }
    }
    if (top == -1) printf("zaebis\n");
    return 0;
}