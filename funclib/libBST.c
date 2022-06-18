#include "libBST.h"

struct BstNode * GetNewNode(int data)
{
    struct BstNode * newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void Insert(struct BstNode ** root, int data)
{
    if (*root == NULL)
    {
        * root = GetNewNode(data);
        return;
    } else if (data <= (*root)->data)
    {
        Insert(&((*root)->left), data);
    } else
    {
        Insert(&((*root)->right), data);
    }
}

struct BstNode * Search(struct BstNode * root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if ((root->data) == data)
    {
        return root;
    } else 
    {
        if (data >= (root->data))
        {
            Search(root->right, data);
        } else
        {
            Search(root->left, data);
        }
    }
}

void Print(struct BstNode * ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    printf("%d ", ptr->data);
    Print(ptr->left);
    Print(ptr->right);
}

int Min(struct BstNode * temp)  // iterative variant
{
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int Max(struct BstNode * temp)
{
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

int FindMin(struct BstNode * temp)
{
    if (temp == NULL)
    {
        return -1;
    }
    if (temp->left == NULL)
    {
        return temp->data;
    } else 
    {
        return FindMin(temp->left);
    }
}

struct BstNode * FindMinRoot(struct BstNode * temp)
{
    if (temp == NULL)
    {
        return temp;
    }
    if (temp->left == NULL)
    {
        return temp;
    } else 
    {
        return FindMinRoot(temp->left);
    }
}

struct BstNode * FindMaxRoot(struct BstNode * temp)
{
    if (temp == NULL)
    {
        return NULL;
    }
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

int FindHeight(struct BstNode * temp)
{
    if (temp == NULL)
    {
        return -1;
    }

    int LeftHeight = FindHeight(temp->left);
    int RightHeight = FindHeight(temp->right);
    int max;
    return max = LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
}

struct BstNode * DeleteNode(struct BstNode * root, int data)
{
    if (root == NULL) return root;
    else if (data < (root)->data) root->left = DeleteNode((root)->left, data);
    else if (data > (root)->data) root->right = DeleteNode((root)->right,data);
    else
    {
        // case 1 (leaf node):
        if ((root)->left == NULL && (root)->right == NULL)
        {
            free(root);
            root = NULL;
        } else 
        if (root->left == NULL)
        {
            struct BstNode * temp = root;
            root = root->right;
            free(temp);
        } else
        if (root->right == NULL)
        {
            struct BstNode * temp = root;
            root = root->left;
            free(temp);
        } else
        {
            struct BstNode * temp = FindMinRoot(root);
            root->data = temp->data;
            root->right = DeleteNode(root->right,temp->data);
        }
    }
    return root;
}

struct BstNode * GetSuccessor(struct BstNode * root, int data)
{
    struct BstNode * current = Search(root,data);
    if (current == NULL) return NULL;
    else if (current->right != NULL)
    {
        return FindMinRoot(current->right);
    } else 
    {
        struct BstNode * successor = NULL;
        struct BstNode * ptr = root;
        while (ptr != current)
        {
            if (current->data < ptr->data)
            {
                successor = ptr;
                ptr = ptr->left;
            } else
            {
                ptr = ptr->right;
            }
        }
        return successor;
    }
}

struct BstNode * GetPredeccessor(struct BstNode * root, int data)
{
    struct BstNode * current = Search(root,data);
    if (current == NULL) return NULL;
    else 
    {
        struct BstNode * ptr = current->left;
        if (ptr->right == NULL)
        {
            return ptr;
        } else if (ptr->right != NULL)
        {
            return FindMaxRoot(ptr->right);
        }
    }
}