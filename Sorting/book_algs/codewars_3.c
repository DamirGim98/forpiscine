#include <stdio.h>
#include <stdlib.h>

typedef struct Pair Pair;
struct Pair {
    long long first;
    long long snd;
};

Pair** removNb(long long n, int* length) {
    Pair ** array = (Pair**)malloc(sizeof(Pair *)*10);
    int k = 0;
    long long sum_to_n = n*(n+1)/2; // for n = 26 sum = 351 
    int x = 2,y = 0;
    while (x < n)
    {
        y = ((sum_to_n - x)/(x + 1));
        if (y < n && ((sum_to_n - x) - y) == x*y)
        {
            Pair * pair = (Pair *)malloc(sizeof(Pair));
            pair->first = x;
            pair->snd = y;
            array[k] = pair;
            k++;
        }
        x++;
    }

    *length = k;
    return array;
}


int main(void)
{
    long long n = 26;
    int length = 0;
    Pair ** arr = removNb(n,&length);
    for (int i = 0; i < length;i++)
    {
        printf("%lld %lld", arr[i]->first, arr[i]->snd);
        printf("\n");
    }
    return 0;
}