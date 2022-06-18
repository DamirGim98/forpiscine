#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10 

typedef struct
{
    char name[MAX_NAME]; 
    int age; 
}person; 

person * hash_table[TABLE_SIZE];

unsigned int hash(char * name)
{
    int length = strlen(name);
    unsigned int char_sum = 0;
    for (int i = 0; i < length; i++)
    {
        char_sum += name[i];
    }
    return char_sum % TABLE_SIZE;
}

bool init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        } else 
        {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
}

bool hash_table_insert(person *p)
{
    if (p == NULL)
    {
        return false;
    }
    int index = hash(p->name);
    if (hash_table[index] != NULL)
    {
        return false;
    }
    hash_table[index] = p;
    return true;
}

person * hash_table_lookup (char * name)
{
    int index = hash(name); 
    if (hash_table[index] != NULL && 
        strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
    {
        return hash_table[index];
    }
}

person * hash_table_delete (char * name)
{
    int index = hash(name); 
    if (hash_table[index] != NULL && 
        strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
    {
        person * tmp = hash_table[index];
        hash_table[index] = NULL;
        return tmp;
    }
}


int main(void)
{
    init_hash_table();
    
    person Damir = {.name="Damir", .age=23};
    person Karen = {.name="Karen", .age=23};
    person Bulat = {.name="Bulat", .age=55};
    person Gulia = {.name="Gulia", .age=52};

    hash_table_insert(&Damir);
    hash_table_insert(&Karen);
    hash_table_insert(&Gulia);
    hash_table_insert(&Bulat);

    print_table();

    person * tmp = hash_table_lookup("Damir");
    if (tmp == NULL)
    {
        printf("its not there");
    } else 
    {
        printf("he is in table %s\n", tmp->name);
    }

    hash_table_delete("Damir");
    print_table();

    // printf("Damir => %u\n", hash("Damir"));
    // printf("Karen => %u\n", hash("Karen"));
    // printf("Bulat => %u\n", hash("Bulat"));
    // printf("Gulya => %u\n", hash("Gulia"));
    return 0;
}
/*
int index = hash("J");
    char name[] = "Li";
    int number = 8999190;
    Insert_friend(&(people[index]), name, number);
    char name1[] = "Kate";
    number = 8999197;
    Insert_friend(&(people[index]), name1, number);
    struct Node * temp = people[index];
    printf("J is friend with %s, %s\n", temp->name, temp->next->name);

    Node J = {.name="J", .number=8991232, .next = NULL};
    Node Li = {.name="Li", .number=89232232, .next = NULL};
    Node Sam = {.name="Sam", .number=82311232, .next = NULL};
    Node Kate = {.name="Kate", .number=8232232, .next = NULL};
    Node Karen = {.name="Karen", .number=8999832, .next = NULL};
    Node Johnny = {.name="Johnny", .number=8978732, .next = NULL};
    Node Salavat = {.name="Salavat", .number=899103452, .next = NULL};
    Node Juliette = {.name="Juliette", .number=8986886, .next = NULL};

    printf("%s %d\n", Vertex_list[0]->name, Vertex_list[0]->number);
    printf("%s %d\n", Vertex_list[1]->name, Vertex_list[1]->number);
    printf("%s %d\n", Vertex_list[2]->name, Vertex_list[2]->number);
    printf("%s %d\n", Vertex_list[3]->name, Vertex_list[3]->number);
    printf("%s %d\n", Vertex_list[4]->name, Vertex_list[4]->number);
    printf("%s %d\n", Vertex_list[5]->name, Vertex_list[5]->number);
    printf("%s %d\n", Vertex_list[6]->name, Vertex_list[6]->number);
    printf("%s %d\n", Vertex_list[7]->name, Vertex_list[7]->number);

    for (int i = 0; name[i] != '\0'; i++)
    {
        printf("%d ", name[i]);
    }
    printf("\n");
    printf("%d\n", hash(name));

    char name[MAX_NAME];
    int number;
    int count = TABLE_SIZE;
    printf("Please enter name of the person:\n");
    scanf("%s", name);
    printf("Ok. We registred %s. Let us know %s's number\n", name, name);
    scanf("%d", &number);


    Add_friend(connections, Vertex_list, "J", "Kate");
    Add_friend(connections, Vertex_list, "J", "Li");

    struct NodePtr * temp = (struct NodePtr *)malloc(sizeof(struct NodePtr));

    temp->friend = table[hash(friend)]; 

    if (connections[hash(name)] == NULL)
    {
        temp->next = NULL;
        connections[hash(name)] = temp;
    } else 
    {
        temp->next = connections[hash(name)];
        connections[hash(name)] = temp;
    }

    printf("%s %s %s\n", connections[0]->friend->name, connections[0]->next->friend->name, connections[0]->next->next->friend->name );
    printf("%s %s %s\n", connections[1]->friend->name, connections[1]->next->friend->name, connections[1]->next->next->friend->name );

    Add_friends(connections, Vertex_list, "J", "Sam Salavat Karen");
    Add_friends(connections, Vertex_list, "Li", "Sam Juliette Kate");
    Add_friends(connections, Vertex_list, "Sam", "J Johnny Li");
    Add_friends(connections, Vertex_list, "Kate", "Juliette Karen Li");
    Add_friends(connections, Vertex_list, "Karen", "J Salavat Juliette Kate");
    Add_friends(connections, Vertex_list, "Johnny", "Sam Salavat Juliette");
    Add_friends(connections, Vertex_list, "Salavat", "J Johnny Juliette Karen");
    Add_friends(connections, Vertex_list, "Juliette", "Salavat Johnny Li Kate Karen");


    temp = connections[hash(name)];
    unsigned int index = -1;
    while (temp->next != NULL)
    {   
        index = whosnumber(connections,temp->friend->name,number);
        if (index != -1)
        {
            return index;
        }
        temp = temp->next;
    }
    */
