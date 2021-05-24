#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/utils.h"
#include "headers/datastructures.h"
#include "headers/cliui.h"

// TODO: Aggiungere funzioni grafi (aggiunta, visualizzazione e rimozione)

void addVertex(Node_t **VertexList, Node_t *AdjacentVertices, Node_t *BridgeList, void *Data) {
	Vertex_t *newVertex = malloc(sizeof(Vertex_t));
	
	if(!newVertex) error(1001);
	
	//AGGIUNTA COLLEGAMENTI E DATI
	newVertex->ID = fetchID();
	newVertex->Data = Data;
	newVertex->AdjacentVertices = AdjacentVertices;
	newVertex->Explored = false;
	newVertex->Visited = false;
	
	if(*VertexList) {
		// TODO: Controllare se esiste già il nodo e creare un nuovo ponte
	}
	
	if(!AdjacentVertices) {
		checkAdjacentVertices(VertexList, BridgeList, AdjacentVertices, newVertex->ID);
	}
	
	endIns(VertexList, newVertex);
}

void linkVertices(Node_t **VertexList, Node_t *BridgeList, unsigned int FirstID, unsigned int SecondID) {
	if(*VertexList == NULL) return;
	
	Vertex_t *tmpVertex; //= malloc(sizeof(Vertex_t));
	tmpVertex = (*VertexList)->Data;
	
	if(tmpVertex->ID == SecondID) {
		if(!checkVertexByID(tmpVertex->AdjacentVertices, FirstID)) {
			endIns(&(tmpVertex->AdjacentVertices), &FirstID);
		}	
	}
	
	linkVertices(&((*VertexList)->next), BridgeList, FirstID, SecondID);
	
}

bool checkVertexByID(Node_t *AdjacentVertices, unsigned int ID) {
	if(AdjacentVertices == NULL) return false;
	
	unsigned int *tmpInt = AdjacentVertices->Data;
	if(*tmpInt == ID) return true;
	
	checkVertexByID(AdjacentVertices->next, ID);
}

void checkAdjacentVertices(Node_t **VertexList, Node_t *BridgeList, Node_t *AdjacentVertices, unsigned int CurrentID) {
	
	if(AdjacentVertices == NULL) return;
	
	unsigned int *tmpInt;
	tmpInt = AdjacentVertices->Data;
	
	linkVertices(VertexList, BridgeList, CurrentID, *tmpInt);
	
	checkAdjacentVertices(VertexList, BridgeList, AdjacentVertices->next, CurrentID);
	
}



