#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include "libBST.h"



bool IsEmpty(int front, int rear);

void Enqueue(struct BstNode * ptr, struct BstNode** A,int * front, int * rear, int N);

void Dequeue(int * front, int * rear, int N);

struct BstNode * FirstOut(int front, struct BstNode** A);

#endif