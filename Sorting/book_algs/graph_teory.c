#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_NAME 10
#define TABLE_SIZE 8

struct Node
{
    char name[MAX_NAME];
    int number; 
};

struct NodePtr
{
    struct Node * friend;
    struct NodePtr * next;
};

unsigned int hash(char name[]);

void init_table(struct NodePtr * table[]);

void Create_person (struct Node * index[], int i);

void Add_friends(struct NodePtr * connections[], struct Node * table[], char name[], char friends[]);

void Is_friend(struct NodePtr * connections[], char name[], char isfriend[]);

void shortest_path(struct NodePtr * connections[], char name[], int number);

bool IsEmpty(int front, int rear);

void Enqueue(struct Node * ptr, struct Node ** A, int * front, int * rear, int N);

struct Node * FirstOut(int front, struct Node ** A);

void Dequeue(int * front, int * rear, int N);


/* START 
OF 
MAIN */

int main(void)
{
    struct NodePtr * connections[TABLE_SIZE]; // array of people in our group.
    init_table(connections);
    struct Node * Vertex_list[TABLE_SIZE]; // array of people itself in network, the reference for other tables to save space.  
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Create_person(Vertex_list, i);
    }

    Add_friends(connections, Vertex_list, "J", "Sam Salavat Karen");
    Add_friends(connections, Vertex_list, "Li", "Sam Juliette Kate");
    Add_friends(connections, Vertex_list, "Sam", "J Johnny Li");
    Add_friends(connections, Vertex_list, "Kate", "Juliette Karen Li");
    Add_friends(connections, Vertex_list, "Karen", "J Salavat Juliette Kate");
    Add_friends(connections, Vertex_list, "Johnny", "Sam Salavat Juliette");
    Add_friends(connections, Vertex_list, "Salavat", "J Johnny Juliette Karen");
    Add_friends(connections, Vertex_list, "Juliette", "Salavat Johnny Li Kate Karen");

    // Is_friend(connections, "Karen", "Kate");
    // Queue implementation 
    struct Node * array[20];
    int N = sizeof(array)/sizeof(struct Node *);
    int front = -1;
    int rear = -1;
    Enqueue(Vertex_list[hash("J")], array ,&front, &rear, N);
    struct Node * temp = NULL;
    
    // printf("%s\n", Vertex_list[whosnumber(connections, "Juliette", 3456)]->name); 
    return 0;
}

/* END 
OF 
MAIN */


unsigned int hash(char name[])
{
    int length = strlen(name) - 1; 
    return length;
}

void init_table(struct NodePtr * table[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }
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

void Add_friends(struct NodePtr * connections[], struct Node * table[], char name[], char friends[])
{   
    char names[40];
    for (int i = 0; friends[i] != '\0'; i++)
    {
        names[i] = friends[i];
    }

    char * token = strtok(names, " ");

    while (token != NULL)
    {
        
        struct NodePtr * temp = (struct NodePtr *)malloc(sizeof(struct NodePtr));

        temp->friend = table[hash(token)]; 

        if (connections[hash(name)] == NULL)
        {
        temp->next = NULL;
        connections[hash(name)] = temp;
        } else 
        {
        temp->next = connections[hash(name)];
        connections[hash(name)] = temp;
        }
        token = strtok(NULL, " ");
    }
}

void Is_friend(struct NodePtr * connections[], char name[], char isfriend[])
{
    struct NodePtr * temp = connections[hash(name)];
    while (temp->next != NULL)
    {
        if (strcmp(temp->friend->name, isfriend) == 0)
        {
            printf("Yes, they are friends!\n");
            printf("Here is %s's number, if you need it %d\n", temp->friend->name, temp->friend->number);
            return;
        }
        temp = temp->next;
    }
    printf("No, they are not\n");
}

void shortest_path(struct NodePtr * connections[], char name[], int number)
{
    
}

bool IsEmpty(int front, int rear)
{
    bool flag = true;
    if (front != -1 && rear != -1)
    {
        flag  = false;
    }
    return flag;
}

void Enqueue(struct Node * ptr, struct Node ** A, int * front, int * rear, int N)
{

    if ((*rear + 1) % N == *front)
    {
        printf("Queue is full");
    } else if (IsEmpty(*front, *rear))
    {
        * front = 0;
        * rear = 0;
        A[*rear] = ptr;
    } else 
    {
        * rear = (*rear + 1) % N;
    }
    A[*rear] = ptr;
}

void Dequeue(int * front, int * rear, int N)
{
    if (IsEmpty(*front, *rear))
    {
        printf("Nothing to dequeue");
    } else if (* front == * rear)
    {
        * front = -1;
        * rear = -1; 
    }
    else {
        *front = ( *front + 1)%N;
    }

}

struct Node * FirstOut(int front, struct Node ** A)
{
    return A[front];
}