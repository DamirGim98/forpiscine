#include <stdlib.h>
#include <stdio.h>

void memory_for_array (int ** ptr, int n)
{
  int * array = (int *)malloc(n*sizeof(int));
  * ptr = array;
  // printf("%p\n", ptr);
}

void fill_array (int n, int * arr)
{
  for (int i = 0; i < n; i++)
  {
    arr[i] = i; 
  }
}
void print_array (int n, int * arr)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]); 
  }
}
int main(void)
{
  printf("How many elemetns?:");
  int n;
  scanf("%d",&n);
  int * start;
  memory_for_array(&start,n);
  // printf("%p\n", start); 
  fill_array(n,start);
  print_array(n, start);

  return 0;
}