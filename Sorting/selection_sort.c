#include <stdio.h>

void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int imin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[imin])
            {
                imin = j;
            }
        }
        int temp = A[i];
        A[i] = A[imin];
        A[imin] = temp;
        printf("%d ", A[i]);
    }
}
int main(void)
{
    int A[] = {15,11,9,4,5};
    int n = sizeof(A) / sizeof(int); 
    SelectionSort(A,n);
    return 0;
}