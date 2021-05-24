#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "datastructures.h"
#include "utils.h"

void headIns(Node_t **Head, void* Data);

void _endIns(Node_t **Head, int Pos, void* Data);

void endIns(Node_t **Head, void *Data);

void printVertexStringList(Node_t **VertexList);

void _freeList(Node_t **Head);

void freeList(Node_t **Head);

#endif
