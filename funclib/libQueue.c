#include "libQueue.h"

bool IsEmpty(int front, int rear)
{
    bool flag = true;
    if (front != -1 && rear != -1)
    {
        flag  = false;
    }
    return flag;
}


void Enqueue(struct BstNode * ptr, struct BstNode** A, int * front, int * rear, int N)
{

    if ((*rear + 1) % N == *front)
    {
        printf("Queue is full");
    } else if (IsEmpty(*front, *rear))
    {
        * front = 0;
        * rear = 0;
        A[*rear] = ptr;
    } else 
    {
        * rear = (*rear + 1) % N;
    }
    A[*rear] = ptr;
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
    else {
        *front = ( *front + 1)%N;
    }

}

struct BstNode * FirstOut(int front, struct BstNode** A)
{
    return A[front];
}