#include "libBST.h"

int main(void)
{
    struct BstNode * root = NULL;
    for (int i = 0; i < 12; i++)
    {
        int a;
        scanf("%d",&a);
        Insert(&root, a);
    }
    // Print(root);
    struct BstNode * temp = NULL;
    temp = GetPredeccessor(root, 12);
    printf("%d ", temp->data);
    // root = DeleteNode(root, 17);
    return 0;
}
