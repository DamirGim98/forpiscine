#include "libBST.h"
#include "libQueue.h"

void IsItBST(struct BstNode * root);

int main(void)
{
    struct BstNode * root = NULL;
    printf("Enter elements one by one:");
    for (int i = 0; i < 10; i++)
    {
        int a = 0;
        scanf("%d", &a);
        Insert(&root,a);
    }
    IsItBST(root);
}

void IsItBST(struct BstNode * root) // level order print
{
    struct BstNode * Array[20];
    int N = sizeof(Array)/sizeof(struct BstNode *);
    int front = -1;
    int rear = -1;
    Enqueue(root,Array,&front,&rear,N);
    struct BstNode * temp;
    int prev = root->data;
    while (!(IsEmpty(front,rear)) && prev <= temp->data)
    {
        temp = FirstOut(front,Array);
        prev = temp->data;
        printf("%d ", temp->data);
        if (temp->left != NULL) Enqueue(temp->left,Array,&front,&rear,N);
        if (temp->right != NULL) Enqueue(temp->right,Array,&front,&rear,N);
        Dequeue(&front,&rear,N);
    }
}