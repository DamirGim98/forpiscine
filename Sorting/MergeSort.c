#include <stdio.h>
#include <stdlib.h>

void Merge(int left[], int right[], int llen, int rlen, int A[])
{ 
    int i = 0, j = 0, k = 0;
    while (i < llen && j < rlen)
    {
        if (left[i] < right[j])
        {
            A[k] = left[i];
            i++;
        } else 
        {
            A[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < llen)
    {
        A[k] = left[i];
        i++;
        k++;
    }
    while (j < rlen)
    {
        A[k] = right[j];
        j++;
        k++;
    }
}
void MergeSort(int A[], int n)
{
    if (n < 2)
    {
        return;
    }
    int mid = n / 2;
    int * left = (int *)malloc(mid*sizeof(int));
    int * right = (int *)malloc((n - mid)*sizeof(int));
    for (int i = 0; i < mid; i++)
    {
        left[i] = A[i];
    }
    for (int i = mid; i < n; i++)
    {
        right[i - mid] = A[i];
    }
    MergeSort(left, mid);
    MergeSort(right, n - mid);
    Merge(left, right, mid, n - mid, A);
        free(left); 
        free(right);
}

int main() {
	
	int A[] = {6,2,3,1,9,10,15,13,12,17}; 
	int i,numberOfElements;
	numberOfElements = sizeof(A)/sizeof(A[0]); 
	MergeSort(A,numberOfElements);
	for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
	return 0;
}