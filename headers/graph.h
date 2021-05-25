#ifndef GRAPH_H
#define GRAPH_H

#include "datastructures.h"
#include "utils.h"

typedef struct {
	unsigned int ID;
	void *Data;
	bool Visited;
	Node_t *AdjacentVertices;
} Vertex_t;

typedef struct {
	IdPair_t VertexPair;
	double MaxWeight;
} Edge_t;

// TODO: Aggiungere prototipi funzioni grafi

void addVertex(Node_t **VertexList, void *Data);

void addEdge(Node_t **VertexList, Node_t *BridgeList, Vertex_t *VertexSource, Vertex_t *VertexDestination, double maxWeight);

void addVerticesAndEdgesFromFileData(Node_t **VertexList);

void createGraphFromFileData(Node_t **VertexList, Node_t **BridgeList);

bool tryRoute(Node_t **VertexList, Node_t **BridgeList, Vertex_t *Source, Vertex_t *Destination, double *TotalWeight);

void crawl(Node_t **VertexList, Node_t **BridgeList, Vertex_t *Source, double *TotalWeight);

#endif
