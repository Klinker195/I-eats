#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

typedef struct Node {
	void *Data;
	struct Node *next;
} Node_t;

Node_t *createNode(void *Data);

void swapNodeData(void **a, void **b);

//#include "queue.h"
#include "linkedlist.h"
#include "graph.h"
//#include "heap.h"

#endif
