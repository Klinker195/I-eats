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

void addEdge(Node_t **VertexList, Node_t *BridgeList, Vertex_t *VertexSource, Vertex_t *VertexDestination, double maxWeight) {
	IdPair_t *tmpIdPair;
	Edge_t *newBridge;
	
	if(searchVertexID(VertexList, VertexSource->ID) && searchVertexID(VertexList, VertexDestination->ID)) {
		if(!(searchVertexID(&(VertexDestination->AdjacentVertices), VertexSource->ID)) && !(searchVertexID(&(VertexSource->AdjacentVertices), VertexDestination->ID))) {
			endIns(&(VertexSource->AdjacentVertices), &VertexDestination->ID);
			endIns(&(VertexDestination->AdjacentVertices), &VertexSource->ID);
			
			tmpIdPair = malloc(sizeof(IdPair_t));
			tmpIdPair->x = VertexSource->ID;
			tmpIdPair->y = VertexDestination->ID;	
			
			if(!searchBridge(&BridgeList, tmpIdPair)) {
				newBridge = malloc(sizeof(Edge_t));
				newBridge->MaxWeight = maxWeight;
				endIns(&BridgeList, newBridge);
			} else {
				printf(ANSI_COLOR_BRIGHTYELLOW "\n\n Errore: Ponte gia' esistente. Creazione del ponte ignorata.\n\n");
			}
		} else {
			printf(ANSI_COLOR_BRIGHTYELLOW "\n\n Errore: Collegamento gia' esistente. Creazione del'arco ignorata.\n\n");
			sleep(2);
			return;
		}
	} else {
		printf(ANSI_COLOR_BRIGHTYELLOW "\n\n Errore: Vertice non presente nel grafo. Creazione del'arco ignorata.\n\n");
		sleep(2);
		return;
	}
}

/*
DEPRECATED
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
*/

// TODO: Funzioni Graph da finire

void addVerticesAndEdgesFromFileData(Node_t **VertexList) {
	// Apertura di tutti i file contenuti all'interno della cartella ./data/islands tramite l'utilizzo di un file di supporto che contiene tutti gli ID presenti nella cartella
	// Creazione vertice da ogni file
	
	FILE *IsleExistingIslands = fopen("./data/islands/ExistingIslands.isle", "r");
	
	if(!IsleExistingIslands) {
		fclose(IsleExistingIslands);
		IsleExistingIslands = fopen("./data/islands/ExistingIslands.isle", "w");
		fclose(IsleExistingIslands);
		IsleExistingIslands = fopen("./data/islands/ExistingIslands.isle", "r");
	}
	
	if(!IsleExistingIslands) error(1001);
	
	String VertexID;
	String FinalPath = "./data/islands/";
	IsleInfo_t *IsleInfo;
	FILE *IsleVertex;
	Vertex_t *newVertex;
	unsigned int intVertexID;
	
	while(!feof(IsleExistingIslands)) {
		fscanf(IsleExistingIslands, "%s", VertexID);
		
		strcat(FinalPath, VertexID);
		strcat(FinalPath, ".isle");
		
		IsleVertex = fopen(FinalPath, "r");
		
		if(!IsleVertex) error(1001);
		
		newVertex = malloc(sizeof(Vertex_t));
		IsleInfo = malloc(sizeof(IsleInfo_t));
		
		intVertexID = atoi(VertexID);
		
		newVertex->ID = intVertexID;
		fscanf(IsleVertex, "%s\n%s\n%lf", IsleInfo->Name, IsleInfo->Resource.Name, &IsleInfo->Resource.SpecificWeight);
		IsleInfo->Resource.Quantity = 1;
		newVertex->Data = IsleInfo;
		newVertex->AdjacentVertices = NULL;
		newVertex->Explored = false;
		newVertex->Visited = false;
		
		fclose(IsleVertex);
	}

	rewind(IsleExistingIslands);

	unsigned int tmpID;
	Vertex_t *tmpVertexSource;
	Vertex_t *tmpVertexDestination;

	while(!feof(IsleExistingIslands)) {
		fscanf(IsleExistingIslands, "%s", VertexID);
		
		strcat(FinalPath, VertexID);
		strcat(FinalPath, ".isle");
		
		IsleVertex = fopen(FinalPath, "r");
		
		if(!IsleVertex) error(1001);
		
		fscanf(IsleVertex, "%*\n%*\n%*\n");
		
		intVertexID = atoi(VertexID);
		
		tmpVertexSource = fetchVertexFromID(VertexList, intVertexID);
		
		while(!feof(IsleExistingIslands)) {
			fscanf(IsleVertex, "%u", &tmpID);
			tmpVertexDestination = fetchVertexFromID(VertexList, tmpID);
			
			endIns(&(tmpVertexSource->AdjacentVertices), &tmpID);
			endIns(&(tmpVertexDestination->AdjacentVertices), &intVertexID);
		}
		
		fclose(IsleVertex);
	}
	
	fclose(IsleExistingIslands);
}

void createGraphFromFileData(Node_t **VertexList, Node_t **BridgeList) {
	addVerticesAndEdgesFromFileData(VertexList);
	endInsBridgesFromFile(BridgeList);
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



