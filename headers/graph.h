#ifndef GRAPH_H
#define GRAPH_H

#include "datastructures.h"
#include "utils.h"

typedef struct {
	unsigned int ID;
	void *Data;
	bool Explored;
	bool Visited;
	Node_t *AdjacentVertices;
} Vertex_t;

typedef struct {
	IdPair_t VertexPair;
	double MaxWeight;
} Edge_t;

// TODO: Aggiungere prototipi funzioni grafi

void addVertex(Node_t **VertexList, void *Data);

void addEdge(Node_t **VertexList, Node_t *BridgeList, Vertex_t *VertexSource, unsigned int VertexDestinationID, double maxWeight);

void addVerticesFromFileData(Node_t **VertexList);

void addEdgesFromFileData();

void createGraphFromFileData(Node_t **VertexList);

// DEPRECATED ???

void checkAdjacentVertices(Node_t **VertexList, Node_t *BridgeList, Node_t *AdjacentVertices, unsigned int CurrentID);

bool checkVertexByID(Node_t *AdjacentVertices, unsigned int ID);

void linkVertices(Node_t **VertexList, Node_t *BridgeList, unsigned int FirstID, unsigned int SecondID);


#endif
