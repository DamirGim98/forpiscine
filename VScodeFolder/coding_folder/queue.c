#include <stdio.h>
#include <stdbool.h>

bool IsEmpty(int front, int rear);

void Enqueue(int x, int * A,int * front, int * rear, int N);

void Dequeue(int * front, int * rear, int N);

void Front(int front, int * A);

int main(void)
{
    int Array[11] = {0};
    int N = sizeof(Array) / sizeof(int);
    int front = -1;
    int rear = -1;
    int s = 0;
    for (int i = 0; i < N; i++)
    {
        printf("Enter value to enqueue\n");
        scanf("%d", &s); 
        Enqueue(s, Array, &front, &rear, N);
    }
    Dequeue(&front, &rear, N);
    Dequeue(&front, &rear, N);
    Dequeue(&front, &rear, N);
    Enqueue(7, Array, &front, &rear, N);
    Enqueue(7, Array, &front, &rear, N);
    Enqueue(7, Array, &front, &rear, N);
    for (int i = 0; i < 10; i++)
    {
        if (i == front)
        {
            printf("|%d-> ", Array[i]);
            continue;
        } else if (i == rear)
        {
            printf("<-%d| ", Array[i]); 
            continue;
        }
        printf("%d ", Array[i]);
    }

}

bool IsEmpty(int front, int rear)
{
    bool flag = true;
    if (front != -1 && rear != -1)
    {
        flag  = false;
    }
    return flag;
}


void Enqueue(int x, int * A, int * front, int * rear, int N)
{

    if ((*rear + 1) % N == *front)
    {
        printf("Queue is full");
    } else if (IsEmpty(*front, *rear))
    {
        * front = 0;
        * rear = 0;
        A[*rear] = x;
    } else 
    {
        * rear = (*rear + 1) % N;
    }
    A[*rear] = x;
}

void Dequeue(int * front, int * rear, int N)
{
    if (IsEmpty(*front, *rear))
    {
        printf("Nothing to dequeue");
    } else if (* front == * rear)
    {
        * front = -1;
        * rear = -1; 
    }
    else *front = ( *front + 1)%N;
}

void FirstOut(int front, int * A)
{
    printf("%d ", A[front]);
}