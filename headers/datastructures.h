#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

typedef struct Node {
	void *Data;
	struct Node *next;
} Node_t;

#include "utils.h"

typedef struct {
	String CF;
	unsigned int IsleID;
	int ItemsQuantity;
	Node_t *Resources;
} Order_t;

Node_t *createNode(void *Data);

#include "graph.h"
#include "linkedlist.h"

#endif
