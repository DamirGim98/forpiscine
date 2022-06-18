#include <stdio.h>
#include <stdbool.h>

void Initialize(int n, int m, char  a[8][8]);
void Print(int n, int m, char  a[8][8]);

int main(void)
{
    int m = 8,n = 8;
    char matrix[n][m]; 
    Initialize(n,m, matrix);
    Print(n,m, matrix);

    
    
}

void Print(int n, int m, char  a[8][8])
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            printf("%c ", a[i][j]); 
        }
        printf("\n");
    }
}

void Initialize(int n, int m, char matrix[8][8])
{
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      matrix[i][j] = 48;
    }
  }
}