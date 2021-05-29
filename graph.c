#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/utils.h"
#include "headers/datastructures.h"
#include "headers/cliui.h"

unsigned int addVertex(Node_t **VertexList, String IsleName) {
	Vertex_t *newVertex = malloc(sizeof(Vertex_t));
	
	if(!newVertex) error(1001);
	
	newVertex->ID = fetchID();
	strcpy(newVertex->IsleName, IsleName);
	newVertex->AdjacentVertices = NULL;
	newVertex->Visited = false;
	
	endIns(VertexList, newVertex);
	return newVertex->ID;
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
				newBridge->VertexPair.x = VertexSource->ID;
				newBridge->VertexPair.y = VertexDestination->ID;
				endIns(&BridgeList, newBridge);
			} else {
				printf(ANSI_COLOR_BRIGHTYELLOW "\n\n Errore: Ponte gia' esistente. Creazione del ponte ignorata.\n\n");
			}
		} else {
			printf(ANSI_COLOR_BRIGHTYELLOW "\n\n Errore: Collegamento gia' esistente. Creazione dell'arco ignorata.\n\n");
			sleep(2);
			return;
		}
	} else {
		printf(ANSI_COLOR_BRIGHTYELLOW "\n\n Errore: Vertice non presente nel grafo. Creazione dell'arco ignorata.\n\n");
		sleep(2);
		return;
	}
}

void addVerticesAndEdgesFromFileData(Node_t **VertexList) {
	
	FILE *IsleExistingIslands = fopen("./data/islands/ExistingIslands.isle", "r");
	
	if(!IsleExistingIslands) {
		fclose(IsleExistingIslands);
		IsleExistingIslands = fopen("./data/islands/ExistingIslands.isle", "w");
		fclose(IsleExistingIslands);
		IsleExistingIslands = fopen("./data/islands/ExistingIslands.isle", "r");
	}
	
	if(!IsleExistingIslands) error(1001);
	
	String VertexID;
	String FinalPath;
	String IsleName;
	FILE *IsleVertex;
	Vertex_t *newVertex;
	unsigned int intVertexID;
	
	while(!feof(IsleExistingIslands)) {
		fscanf(IsleExistingIslands, "%s", VertexID);
		
		strcpy(FinalPath, "");
		strcpy(FinalPath, "./data/islands/");
		
		strcat(FinalPath, VertexID);
		strcat(FinalPath, ".isle");
		
		IsleVertex = fopen(FinalPath, "r");
		
		if(!IsleVertex) error(1001);
		
		newVertex = malloc(sizeof(Vertex_t));
		
		intVertexID = atoi(VertexID);
		
		newVertex->ID = intVertexID;
		fscanf(IsleVertex, "%s\n", IsleName);
		strcpy(newVertex->IsleName, IsleName);
		newVertex->AdjacentVertices = NULL;
		newVertex->Visited = false;
		
		endIns(VertexList, newVertex);
		
		fclose(IsleVertex);
	}

	rewind(IsleExistingIslands);

	unsigned int tmpID;
	unsigned int *tmpIDPointer;
	Vertex_t *tmpVertexSource;
	Vertex_t *tmpVertexDestination;
	unsigned int *intVertexIDPointer;
	String tmpBuff;

	while(!feof(IsleExistingIslands)) {
		fscanf(IsleExistingIslands, "%s", VertexID);
		
		strcpy(FinalPath, "");
		strcpy(FinalPath, "./data/islands/");
		
		strcat(FinalPath, VertexID);
		strcat(FinalPath, ".isle");
		
		IsleVertex = fopen(FinalPath, "r");
		
		if(!IsleVertex) error(1001);
		
		fscanf(IsleVertex, "%s\n", tmpBuff);
		
		intVertexID = atoi(VertexID);
		
		intVertexIDPointer = malloc(sizeof(unsigned int *));
		
		*intVertexIDPointer = (unsigned int)intVertexID;
		
		tmpVertexSource = fetchVertexFromID(VertexList, *intVertexIDPointer);
		
		while(!feof(IsleVertex)) {
			fscanf(IsleVertex, "%u", &tmpID);
			tmpIDPointer = malloc(sizeof(unsigned int *));
			*tmpIDPointer = (unsigned int)tmpID;
			
			endIns(&(tmpVertexSource->AdjacentVertices), tmpIDPointer);
		}
		
		fclose(IsleVertex);
	}
	
	fclose(IsleExistingIslands);
}

void createGraphFromFileData(Node_t **VertexList, Node_t **BridgeList) {
	addVerticesAndEdgesFromFileData(VertexList);
	endInsBridgesFromFile(BridgeList);
}

void resetVisitedVertexList(Node_t **VertexList) {
	if(*VertexList == NULL) return;
	
	Vertex_t *tmpVertex;
	
	tmpVertex = (*VertexList)->Data;
	
	tmpVertex->Visited = false;
	
	resetVisitedVertexList(&((*VertexList)->next));
}

bool tryRoute(Node_t **VertexList, Node_t **BridgeList, Vertex_t *Source, Vertex_t *Destination, double TotalWeight) {
	crawl(VertexList, BridgeList, Source, TotalWeight);
	
	if(Destination->Visited) {
		resetVisitedVertexList(VertexList);
		return true;
	} else {
		resetVisitedVertexList(VertexList);
		return false;
	}
	
}

void crawl(Node_t **VertexList, Node_t **BridgeList, Vertex_t *Source, double TotalWeight) {
	Source->Visited = true;
	Node_t *tmpAdjacentVertices = Source->AdjacentVertices;
	
	if(!tmpAdjacentVertices) return;
	
	unsigned int *tmpID;
	Vertex_t *tmpVertex;
	IdPair_t tmpIdPair;
	
	while(tmpAdjacentVertices != NULL) {
		tmpID = tmpAdjacentVertices->Data;
		tmpVertex = fetchVertexFromID(VertexList, *tmpID);
		
		tmpIdPair.x = Source->ID;
		tmpIdPair.y = tmpVertex->ID;
		
		if(!tmpVertex->Visited) {
			if(tryBridge(BridgeList, &tmpIdPair, TotalWeight)) {
				crawl(VertexList, BridgeList, tmpVertex, TotalWeight);
			}
		}
		
		tmpAdjacentVertices = tmpAdjacentVertices->next;
	}
	
}



