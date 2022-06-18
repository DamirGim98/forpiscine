#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 10
#define TABLE_SIZE 8
#define I 32767

struct Node
{
    char name[MAX_NAME];
    int number; 
};

bool Is_friend(int matrix[][8]);
unsigned int hash(char name[]);
void Create_person (struct Node * table[], int i);
bool Is_friend(int matrix[][8]);
void BFS(int matrix[][8], char start[], struct Node * list[]);
void DFS(int matrix[][8], char start[], struct Node * list[]);
int Dequeue(int A[],int * front, int * rear, int N);
void Enqueue(int index, int A[], int * front, int * rear, int N);
bool IsEmpty(int front, int rear);
void Prime(int matrix[][8]);

int main(void)
{
    int matrix[8][8] = {{I,I,3,I,21,I,6,I}, // 0
                        {I,I,11,4,I,I,I,19},// 1
                        {3,11,I,I,I,13,I,I},// 2 
                        {I,4,I,I,1,I,I,5}, //3
                        {21,I,I,1,I,I,17,7},// 4
                        {I,I,13,I,I,I,2,8}, //5 
                        {6,I,I,I,17,2,I,9}, // 6
                        {I,19,I,5,7, 8, 9,I}}; // 7

    struct Node * Vertex_list[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Create_person(Vertex_list, i);
    }

    // BFS(matrix, "Kate", Vertex_list);
    // DFS(matrix, "Kate", Vertex_list);
    // printf("%d\n" , Is_friend(matrix));

    Prime(matrix);
    return 0;
}

void Create_person (struct Node * table[], int i)
{
    char names[][8] = {"J","Li","Sam","Kate","Karen","Johnny","Salavat","Juliette"};
    int number[] = {3456, 7788, 9900, 1122, 3435, 4421, 7734, 7500};

    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    for (int j = 0; j < strlen(names[i]); j++)
    {
        (temp->name)[j] = names[i][j];
    }
    temp->number = number[i];
    (table)[hash(temp->name)] = temp;
}

unsigned int hash(char name[])
{
    int length = strlen(name) - 1; 
    return length;
}

bool Is_friend(int matrix[][8])
{   
    char name[10];
    char friend[10];
    printf("Plese enter the name of the person and them name of the friend you want to check\n");
    scanf("%s %s", name, friend);
    bool flag = false;
    int i = hash(name);
    int j = hash(friend);
    if (matrix[i][j] == 8)
    {
        flag = true;
    }
    return flag;
}

void BFS(int matrix[][8], char start[], struct Node * list[])
{
    int * queue = (int *)malloc(TABLE_SIZE*sizeof(int));
    int * visited = (int *)malloc(TABLE_SIZE*sizeof(int));
    for (int i = 0; i < TABLE_SIZE; i ++)
    {
        visited[i] = 0;
    }

    int front = I;
    int rear = I;

    printf("%s\n", list[hash(start)]->name);
    visited[hash(start)] = 1;
    // printf("%d ", visited[1]);
    Enqueue(hash(start), queue, &front, &rear, TABLE_SIZE);
    while (!IsEmpty(front, rear))
    {
        int u = Dequeue(queue, &front, &rear, TABLE_SIZE);
        for (int v = 0; v < TABLE_SIZE; v++)
        {
            if (matrix[u][v] != I && visited[v] == 0)
            {
                printf("%s\n",list[v]->name);
                visited[v] = 1;
                Enqueue(v, queue, &front, &rear, TABLE_SIZE);
            }
        }
    }
}

void DFS(int matrix[][8], char start[], struct Node * list[])
{
    static int visited[TABLE_SIZE] = {0};
    int i = hash(start);
    if (visited[i] == 0)
    {
        printf("%s\n", list[i]->name);
        visited[i] = 1;
        for (int v = 0; v < TABLE_SIZE; v++)
        {
            if (matrix[i][v] != I)
            {
                DFS(matrix,list[v]->name, list);
            }
        }
    }
}

void Enqueue(int index, int A[], int * front, int * rear, int N)
{

    if ((*rear + 1) % N == *front)
    {
        printf("Queue is full");
    } else if (IsEmpty(*front, *rear))
    {
        * front = 0;
        * rear = 0;
        A[*rear] = index;
    } else 
    {
        * rear = (*rear + 1) % N;
    }
    A[*rear] = index;
}

int Dequeue(int A[],int * front, int * rear, int N)
{
    int index;
    if (IsEmpty(*front, *rear))
    {
        printf("Nothing to dequeue");
    } else if (* front == * rear)
    {
        * front = I;
        * rear = I; 
    }
    else {
        index = A[* front];
        *front = ( *front + 1)%N;
    }
    return index;

}

bool IsEmpty(int front, int rear)
{
    bool flag = true;
    if (front != I && rear != I)
    {
        flag  = false;
    }
    return flag;
}

void Prime(int matrix[][8])
{   
    int min = I;
    int r = 2,c = 7,u,v,k, n = 7;
    int t[2][7];
    int near[8] = {I,I,I,I,I,I,I,I}; 

    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                u = i;
                v = j;
            }
        }
    }

    t[0][0] = u;
    t[1][0] = v;
    near[u] = 99;
    near[v]= 99;

    for (int i = 0; i <= n; i++)
    {
        if (near[i] != 99)
        {
            if ((matrix[i][u] < matrix[i][v]))
            {
                near[i] = u;
            } else 
            {
                near[i] = v;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        min = I;
        for (int j = 0; j <= n; j++)
        {
            if (near[j] != 99 && (matrix[j][near[j]] < min))
            {
                min = matrix[j][near[j]];
                k = j;
            }
        }

        t[0][i] = k; t[1][i] = near[k];
        near[k] = 99;

        for (int j = 0; j <= n;j++)
        {
            if (near[j] != 99 && (matrix[j][k] < matrix[j][near[j]]))
            {
                near[j] = k;
            }
        }
    }

    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            printf("%d ", t[x][y]);
        }
        printf("\n");
    }
}