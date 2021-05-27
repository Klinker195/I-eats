#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "datastructures.h"
#include "graph.h"
#include "utils.h"

void headIns(Node_t **Head, void* Data);

void _endIns(Node_t **Head, int Pos, void* Data);

void endIns(Node_t **Head, void *Data);

int printVertexList(Node_t **VertexList);

void printBridgeStringList(Node_t **BridgeList);

bool searchBridge(Node_t **BridgeList, IdPair_t *VertexIdPair);

bool tryBridge(Node_t **BridgeList, IdPair_t *VertexIdPair, double TotalWeight);

Vertex_t *fetchVertexFromID(Node_t **VertexList, unsigned int VertexID);

bool searchVertexID(Node_t **VertexList, unsigned int VertexID);

int printResourcesList(Node_t **Head);

int printOrderRecapList(Node_t **Head);

void endInsBridgesFromFile(Node_t **Head);

void endInsVehicleOwnerFromFile(Node_t **Head);

void endInsVehiclesFromFile(Node_t **Head);

void endInsResourcesFromFile(Node_t **Head);

bool searchInt(Node_t **Head, int RequestedInteger);

Vehicle_t *fetchVehicleFromModel(Node_t **Head, String Model);

Vertex_t *_fetchVertexAtPosition(Node_t **Head, int Pos, int CurrentPos);

Vertex_t *fetchVertexAtPosition(Node_t **Head, int Pos);

Resource_t *_fetchResourceAtPosition(Node_t **Head, int Pos, int CurrentPos);

Resource_t *fetchResourceAtPosition(Node_t **Head, int Pos);

bool _deleteResourceAtPosition(Node_t **Head, int Pos, int CurrentPos);

bool deleteResourceAtPosition(Node_t **Head, int Pos);

void writeListIntoVehicleOwnersFile(Node_t **List, FILE *IsleVehicleOwners);

void writeListIntoResourcesFile(Node_t **List, FILE *IsleResourceData);

void _writeListIntoOrderFile(Node_t **List, String UserCF, unsigned int VertexID, FILE *IsleOrderData, int Position);

void writeListIntoOrderFile(Node_t **List, String UserCF, unsigned int VertexID, FILE *IsleOrderData);

void _freeList(Node_t **Head);

void freeList(Node_t **Head);

#endif
