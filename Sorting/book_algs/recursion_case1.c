#include <stdio.h>
#include <stdlib.h>

int sum_array(int * array, int index);

int find_max(int * array, int index, int max); 

int main(void)
{
    int array[10] = {1,2,3,4,5,100,7,8,9,10};
    int index = 0; 
    int max = -999;
    // printf("%d", sum_array(array, 0));
    printf("%d", find_max(array, index, max));  
}

int sum_array(int * array, int index)
{
    if (index <= 9)
    {
        return array[index] + sum_array(array ,index + 1); 
    }
    else return 0;
}

int find_max(int * array, int index, int max)
{
    if (index <= 9)
    {
        max = array[index] > max ? array[index] : max;
        find_max(array, index + 1,max);
    }
    else
    {
        return max;
    }
}



