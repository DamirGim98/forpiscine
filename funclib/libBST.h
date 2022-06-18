#ifndef BSTLIB_H
#define BSTLIB_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct BstNode
{
    int data;
    struct BstNode * left;
    struct BstNode * right;
};

struct BstNode * GetPredeccessor(struct BstNode * root, int data);

struct BstNode * GetSuccessor(struct BstNode * root, int data);

struct BstNode * DeleteNode(struct BstNode * root, int data);

void Insert(struct BstNode ** root, int x);

struct BstNode * Search(struct BstNode * root, int data);

void Print(struct BstNode * ptr);

int Min(struct BstNode * temp);

int Max(struct BstNode * temp);

int FindMin(struct BstNode * temp);

struct BstNode * FindMinRoot(struct BstNode * temp);

struct BstNode * FindMaxRoot(struct BstNode * temp);

int FindHeight(struct BstNode * temp);

#endif