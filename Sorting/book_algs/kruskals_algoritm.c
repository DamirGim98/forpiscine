#include <stdio.h>
#include <stdlib.h>

#define I 32767

void uni (int * matrix, int u, int v);

int find(int * matrix, int u);

int main(void)
{
    int edge_matrix[][9] = {{1,1,2,2,3,4,4,5,5},
                            {2,6,3,7,4,5,7,6,7},
                            {25,5,12,10,8,16,14,20,18}};
    int included[9] = {0,0,0,0,0,0,0,0,0};
    int t[2][6];
    int set[8] = {I, -1,-1,-1,-1,-1,-1,-1};

    int i = 0,j,k,n = 7, e = 9, min, u, v;

    while (i < n -1)
    {
        min = I;
        for (j = 0; j < e; j++)
        {
            if (included[j] == 0)
            {
                if (edge_matrix[2][j] < min)
                {
                    min = edge_matrix[2][j];
                    k = j;
                    u = edge_matrix[0][j];
                    v = edge_matrix[1][j];
                }
            }
        }
        if (find(set, u) != find(set, v))
        {
            t[0][i] = u; t[1][i] = v;
            uni(set,find(set,u), find(set,v));
            i++;
        }
        included[k] = 1;
    }

    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 6; y++)
        {
            printf("%d ", t[x][y]);
        }
        printf("\n");
    }
}

void uni (int * matrix, int u, int v)
{
    if (matrix[u] < matrix[v])
    {
        matrix[u] = matrix[u] + matrix[v];
        matrix[v] = u;
    } else 
    {
        matrix[v] = matrix[u] + matrix[v];
        matrix[u] = v;
    }
}

int find(int * matrix, int u)
{
    int x = u; 
    while (matrix[x] > 0)
    {
        x = matrix[x];
    }
    return x;
}