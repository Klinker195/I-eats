#ifndef GRAPH_H
#define GRAPH_H

#include "datastructures.h"
#include "utils.h"

typedef struct {
	unsigned int ID;
	void *Data;
	Node_t *AdjacentVertices;
} Vertex_t;

typedef struct {
	IdPair_t VertexPair;
	double MaxWeight;
} Edge_t;

// TODO: Aggiungere prototipi funzioni grafi

#endif
