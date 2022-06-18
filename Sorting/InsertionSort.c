#include <stdio.h>
#include <math.h>

void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int value = A[i];
        int hole = i;
        while (hole > 0 && A[hole - 1] > value)
        {
            A[hole] = A[hole - 1];
            hole--;
        }
        A[hole] = value;
    }
}
int main(void)
{
    int A[] = {7,11,9,4,5};
    int n = sizeof(A) / sizeof(int); 
    InsertionSort(A,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("%f\n", pow(1,3));
    return 0;
}