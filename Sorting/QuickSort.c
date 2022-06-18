#include <stdio.h>
#include <stdlib.h>

int Partition(int A[], int start, int end);

void QuickSort(int A[], int start, int end)
{
    if(start < end)
    {
        int Pindex = Partition(A, start, end);
        QuickSort(A,start, Pindex - 1);
        QuickSort(A, Pindex + 1, end);
    }
}
int Partition(int A[], int start, int end)
{
    int pivot = A[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (A[i] <=  pivot)
        {
            int temp = A[i];
            A[i] = A[pIndex];
            A[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = A[end];
    A[end] = A[pIndex];
    A[pIndex] = temp;
    return pIndex;
}
int main() {
	
	int A[] = {6,2,3,1,9,10,15,13,12,17}; 
	int i,numberOfElements;
	numberOfElements = sizeof(A)/sizeof(A[0]); 
	QuickSort(A,0,numberOfElements-1);
	for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
	return 0;
}