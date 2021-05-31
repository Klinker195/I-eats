#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "datastructures.h"
#include "graph.h"

void headIns(Node_t **Head, void* Data);

void _endIns(Node_t **Head, int Pos, void* Data);

void endIns(Node_t **Head, void *Data);

void copyList(Node_t **Destination, Node_t **Source);

int printMinimumRouteList(Node_t **VertexList);

int printVertexList(Node_t **VertexList);

int printOrderList(Node_t **OrderList);

void printBridgeStringList(Node_t **BridgeList);

bool searchBridge(Node_t **BridgeList, IdPair_t *VertexIdPair);

bool tryBridge(Node_t **BridgeList, IdPair_t *VertexIdPair, double TotalWeight);

Vertex_t *fetchVertexFromID(Node_t **VertexList, unsigned int VertexID);

bool searchVertexID(Node_t **VertexList, unsigned int VertexID);

int countOrderItems(Node_t **OrderItems);

int printResourcesList(Node_t **Head);

int printOrderRecapList(Node_t **Head);

void endInsBridgesFromFile(Node_t **Head);

void endInsOrderFromFile(Node_t **Head);

void endInsVehicleOwnerFromFile(Node_t **Head);

void endInsVehiclesFromFile(Node_t **Head);

void endInsResourcesFromFile(Node_t **Head);

bool searchInt(Node_t **Head, int RequestedInteger);

int countList(Node_t **Head);

Vertex_t *getRandomStartingVertex(Node_t **Head);

Vehicle_t *fetchVehicleFromModel(Node_t **Head, String Model);

Vertex_t *_fetchVertexAtPosition(Node_t **Head, int Pos, int CurrentPos);

Vertex_t *fetchVertexAtPosition(Node_t **Head, int Pos);

Order_t *_fetchOrderAtPosition(Node_t **Head, int Pos, int CurrentPos);

Order_t *fetchOrderAtPosition(Node_t **Head, int Pos);

Resource_t *_fetchResourceAtPosition(Node_t **Head, int Pos, int CurrentPos);

Resource_t *fetchResourceAtPosition(Node_t **Head, int Pos);

void fetchAndSetSpecificWeightFromFile(Node_t **ResourceOrderList, FILE *IsleResourceData);

bool _deleteBridgeAtVertexID(Node_t **Head, unsigned int VertexID, int CurrentPos);

bool deleteBridgeAtVertexID(Node_t **Head, unsigned int VertexID);

bool _deleteIntAtVertexID(Node_t **Head, unsigned int VertexID, int CurrentPos);

bool deleteIntAtVertexID(Node_t **Head, unsigned int VertexID);
	
bool deleteAdjacentVerticesAtVertexID(Node_t **Head, unsigned int VertexID);
	
bool _deleteVertexAtPosition(Node_t **Head, int Pos, int CurrentPos);

bool deleteVertexAtPosition(Node_t **Head, int Pos);

bool _deleteOrderAtPosition(Node_t **Head, int Pos, int CurrentPos);

bool deleteOrderAtPosition(Node_t **Head, int Pos);

bool _deleteOrderAtCF(Node_t **Head, String UserCF, int CurrentPos);

bool deleteOrderAtCF(Node_t **Head, String UserCF);

bool _deleteResourceAtPosition(Node_t **Head, int Pos, int CurrentPos);

bool deleteResourceAtPosition(Node_t **Head, int Pos);

void writeListIntoVehicleOwnersFile(Node_t **List, FILE *IsleVehicleOwners);

void writeListIntoResourcesFile(Node_t **List, FILE *IsleResourceData);

void _writeVertexListIntoIsleFolderAndFile(Node_t **List, FILE *IsleIslandsData);

void writeVertexListIntoIsleFolderAndFile(Node_t **List, FILE *IsleIslandsData);

void removeAllIslandFiles(Node_t **List);

void writeBridgeListIntoBridgeFile(Node_t **List, FILE *IsleBridgeData);

void writeOrderListIntoOrderFile(Node_t **List, FILE *IsleOrderData);

void _writeListIntoOrderFile(Node_t **List, String UserCF, unsigned int VertexID, int ItemsQuantity, FILE *IsleOrderData, int Position);

void writeListIntoOrderFile(Node_t **List, String UserCF, unsigned int VertexID, int ItemsQuantity, FILE *IsleOrderData);

double _calcTotalWeight(Node_t **ResourceList);

double calcTotalWeight(Vehicle_t Vehicle, Node_t **ResourceList);

void _freeList(Node_t **Head);

void freeList(Node_t **Head);

#endif
