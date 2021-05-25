#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "datastructures.h"
#include "graph.h"
#include "utils.h"

void headIns(Node_t **Head, void* Data);

void _endIns(Node_t **Head, int Pos, void* Data);

void endIns(Node_t **Head, void *Data);

void printVertexStringList(Node_t **VertexList);

bool searchBridge(Node_t **BridgeList, IdPair_t *VertexIdPair);

bool tryBridge(Node_t **BridgeList, IdPair_t *VertexIdPair, double TotalWeight);

Vertex_t *fetchVertexFromID(Node_t **VertexList, unsigned int VertexID);

bool searchVertexID(Node_t **VertexList, unsigned int VertexID);

int printResourcesList(Node_t **Head);

void endInsBridgesFromFile(Node_t **Head);

void endInsResourcesFromFile(Node_t **Head);

void endInsOrderFromList(int ID, Node_t **HeadResource, Node_t **HeadOrder);

bool _deleteResourceAtPosition(Node_t **Head, int Pos, int CurrentPos);

bool deleteResourceAtPosition(Node_t **Head, int Pos);

void writeListIntoResourcesFile(Node_t **List, FILE *IsleResourceData);

void _freeList(Node_t **Head);

void freeList(Node_t **Head);

#endif
