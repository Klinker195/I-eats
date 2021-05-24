#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/utils.h"
#include "headers/datastructures.h"
#include "headers/cliui.h"

// TODO: Aggiungere funzioni grafi (aggiunta, visualizzazione e rimozione)

void addVertex(Node_t **VertexList, void *Data) {
	Vertex_t *newVertex = malloc(sizeof(Vertex_t));
	
	if(!newVertex) error(1001);
	
	newVertex->ID = fetchID();
	newVertex->Data = Data;
	newVertex->AdjacentVertices = NULL;
	newVertex->Explored = false;
	newVertex->Visited = false;
	
	endIns(VertexList, newVertex);
}

void addEdge(Node_t **VertexList, Node_t *BridgeList, Vertex_t *VertexSource, unsigned int VertexDestinationID, double maxWeight) {
	IdPair_t *tmpIdPair;
	Edge_t *newBridge;
	
	if(searchVertexID(VertexList, VertexDestinationID)) {
		endIns(&(VertexSource->AdjacentVertices), &VertexDestinationID);
		tmpIdPair = malloc(sizeof(IdPair_t));
		tmpIdPair->x = VertexSource->ID;
		tmpIdPair->y = VertexDestinationID;
		if(!searchBridge(&BridgeList, tmpIdPair)) {
			newBridge = malloc(sizeof(Edge_t));
			newBridge->MaxWeight = maxWeight;
			endIns(&BridgeList, newBridge);
		} else {
			printf(ANSI_COLOR_BRIGHTYELLOW "\n\n Errore: Ponte gia' esistente. Creazione del ponte ignorata.\n\n");
		}
	}
}

// TODO: Funzioni Graph da finire

void addVerticesFromFileData(Node_t **VertexList) {
	// Apertura di tutti i file contenuti all'interno della cartella ./data/islands tramite l'utilizzo di un file di supporto che contiene tutti gli ID presenti nella cartella
	// Creazione vertice da ogni file
}

void addEdgesFromFileData() {
	// Apertura di tutti i file contenuti all'interno della cartella ./data/islands tramite l'utilizzo di un file di supporto che contiene tutti gli ID presenti nella cartella
	// Creazione archi per ogni file
}

void createGraphFromFileData(Node_t **VertexList) {
	addVerticesFromFileData(VertexList);
	addEdgesFromFileData();
}


// DEPRECATED ???

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



