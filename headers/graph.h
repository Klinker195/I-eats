#ifndef GRAPH_H
#define GRAPH_H

#include "utils.h"
#include "datastructures.h"

typedef struct {
	unsigned int ID;
	String IsleName;
	bool Visited;
	bool Explored;
	Node_t *AdjacentVertices;
} Vertex_t;

typedef struct {
	IdPair_t VertexPair;
	double MaxWeight;
} Edge_t;

unsigned int addVertex(Node_t **VertexList, String IsleName);

void addEdge(Node_t **VertexList, Node_t *BridgeList, Vertex_t *VertexSource, Vertex_t *VertexDestination, double maxWeight);

void addVerticesAndEdgesFromFileData(Node_t **VertexList);

void createGraphFromFileData(Node_t **VertexList, Node_t **BridgeList);

void resetVisitedExploredVertexList(Node_t **VertexList);

void resetVisitedVertexList(Node_t **VertexList);

bool tryRoute(Node_t **VertexList, Node_t **BridgeList, Vertex_t *Source, Vertex_t *Destination, double TotalWeight);

void crawl(Node_t **VertexList, Node_t **BridgeList, Vertex_t *StartingSource, Vertex_t *Source, Vertex_t *Destination, double TotalWeight, Node_t **MinimumList, Node_t **tmpMinimumList);

#endif
