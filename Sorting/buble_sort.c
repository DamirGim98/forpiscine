#include <stdio.h>
#include <stdbool.h>

void BubbleSort(int A[], int n)
{
    for (int k = 0; k < n - 1; k++)
    {
        bool flag = false;
        for (int i = 0; i < n - k; i++)
        {
            if (A[i] > A[i+1])
            {
                int temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                flag = true;
            }
        }
        if (flag == false) break;       
    }
}

int main(void)
{
    int A[] = {7,11,9,4,5};
    int n = sizeof(A) / sizeof(int); 
    BubbleSort(A,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}