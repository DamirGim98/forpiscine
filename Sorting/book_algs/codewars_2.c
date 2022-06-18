#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int compare (const void *x_void, const void * y_void)
{
    int x = *(int *)x_void;
    int y = *(int *)y_void;
    return x-y;
}
bool comp(const int *a, const int *b, size_t n)
{
    if (a == NULL || b == NULL) return false;
    size_t t = n;
    int a1[t];
    int b1[t];
    for (size_t i = 0; i < t; i++)
    {
        a1[i] = a[i];
        b1[i] = b[i];
    }
    qsort(a1,t,sizeof(int), compare);
    qsort(b1,t,sizeof(int), compare);
    for (size_t i = 0; i < t; i++)
    {
        printf("%d ", a1[i]);
    }
    printf("\n");
    for (size_t i = 0; i < t; i++)
    {
        printf("%d ", b1[i]);
    }
    printf("\n");
    for (size_t i = 0; i < t; i++)
    {
        if (a1[i] == b1[i] || (a1[i] * a1[i]) == b1[i])
        {
            continue;
        } else 
        {
            return false;
        }
    }
    return true;
}
int main(void)
{
    int a[9] = {121, 144, 19, 161, 19, 144, 19, 11, 1008};
    int b[9] = {14641, 20736, 361, 25921, 361, 20736, 362, 121, 12340};
    printf("%d\n", comp(a,b,9));
    return 0;
}