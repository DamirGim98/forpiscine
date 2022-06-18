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

bool Search(struct BstNode * root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if ((root->data) == data)
    {
        return true;
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