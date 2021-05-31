#include <stdlib.h>
#include <stdio.h>
#include "headers/datastructures.h"
#include "headers/utils.h"

Node_t *createNode(void *Data) {
	
	Node_t *newNode = malloc(sizeof(Node_t));
	
	if(!newNode) error(1001);
	
	newNode->Data = Data;
	newNode->next = NULL;
	
	return newNode;
}
