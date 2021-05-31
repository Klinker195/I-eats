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
	newVertex->Explored = false;
	
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
		newVertex->Explored = false;
		
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

void resetVisitedExploredVertexList(Node_t **VertexList) {
	if(*VertexList == NULL) return;
	
	Vertex_t *tmpVertex;
	
	tmpVertex = (*VertexList)->Data;
	
	tmpVertex->Explored = false;
	tmpVertex->Visited = false;
	
	resetVisitedVertexList(&((*VertexList)->next));
}

void resetVisitedVertexList(Node_t **VertexList) {
	if(*VertexList == NULL) return;
	
	Vertex_t *tmpVertex;
	
	tmpVertex = (*VertexList)->Data;
	
	tmpVertex->Visited = false;
	
	resetVisitedVertexList(&((*VertexList)->next));
}

bool tryRoute(Node_t **VertexList, Node_t **BridgeList, Vertex_t *Source, Vertex_t *Destination, double TotalWeight) {
	
	if(Destination->ID == Source->ID) {
		printf("\n\n Ti trovi gia' nell'Isola %s [ID: %u]! ", Source->IsleName, Source->ID);
		sleep(2);
		return true;
	}
	
	Node_t *MinimumList = NULL;
	Node_t *tmpMinimumList = NULL;
	
	Node_t *tmpAdjacentVertices = Source->AdjacentVertices;
	unsigned int *tmpID;
	Vertex_t *tmpVertex;
	IdPair_t tmpIdPair;
	
	resetVisitedVertexList(VertexList);
	
	Source->Explored = true;
	
	while(tmpAdjacentVertices != NULL) {
		tmpID = tmpAdjacentVertices->Data;
		tmpVertex = fetchVertexFromID(VertexList, *tmpID);
		
		tmpIdPair.x = Source->ID;
		tmpIdPair.y = tmpVertex->ID;
		
		if(tryBridge(BridgeList, &tmpIdPair, TotalWeight)) {
			tmpVertex->Explored = true;
			crawl(VertexList, BridgeList, tmpVertex, tmpVertex, Destination, TotalWeight, &MinimumList, &tmpMinimumList);
		}
		
		if(Destination->Explored) {
			Destination->Explored = false;
			if(MinimumList == NULL) {
				Destination->Explored = false;
				copyList(&MinimumList, &tmpMinimumList);
				freeList(&tmpMinimumList);
			} else {
				int Min = findMin(countList(&MinimumList), countList(&tmpMinimumList));
				
				if(Min == 0) {
					freeList(&tmpMinimumList);
				} else {
					freeList(&MinimumList);
					copyList(&MinimumList, &tmpMinimumList);
					freeList(&tmpMinimumList);
				}
			}
		}
		
		tmpAdjacentVertices = tmpAdjacentVertices->next;
	}
	
	headIns(&MinimumList, Source);
	if(searchVertexID(&MinimumList, Destination->ID)) {
		printMinimumRouteList(&MinimumList);
		printf("\n\n ");
		system("pause");
		resetVisitedExploredVertexList(VertexList);
		return true;
	} else {
		resetVisitedExploredVertexList(VertexList);
		return false;
	}
}

void crawl(Node_t **VertexList, Node_t **BridgeList, Vertex_t *StartingSource, Vertex_t *Source, Vertex_t *Destination, double TotalWeight, Node_t **MinimumList, Node_t **tmpMinimumList) {
	Node_t *tmpAdjacentVertices = Source->AdjacentVertices;
	Source->Visited = true;
	
	if(Source->ID == Destination->ID) {
		Destination->Explored = true;
		headIns(tmpMinimumList, Source);
		return;
	}

	unsigned int *tmpID;
	Vertex_t *tmpVertex;
	IdPair_t tmpIdPair;
	
	while(tmpAdjacentVertices != NULL) {
		Source->Visited = true;
		tmpID = tmpAdjacentVertices->Data;
		tmpVertex = fetchVertexFromID(VertexList, *tmpID);
		
		tmpIdPair.x = Source->ID;
		tmpIdPair.y = tmpVertex->ID;
		
		if(!tmpVertex->Visited && !tmpVertex->Explored) {
			if(tryBridge(BridgeList, &tmpIdPair, TotalWeight)) {
				crawl(VertexList, BridgeList, StartingSource, tmpVertex, Destination, TotalWeight, MinimumList, tmpMinimumList);
				
				if(Destination->Explored) {
					headIns(tmpMinimumList, Source);
				}
			}
		}
		
		if(Destination->Explored && Source->ID == StartingSource->ID) {
			Destination->Explored = false;
			if(*MinimumList == NULL) {
				Destination->Explored = false;
				copyList(MinimumList, tmpMinimumList);
				freeList(tmpMinimumList);
			} else {
				int Min = findMin(countList(MinimumList), countList(tmpMinimumList));
				
				if(Min == 0) {
					freeList(tmpMinimumList);
				} else {
					freeList(MinimumList);
					copyList(MinimumList, tmpMinimumList);
					freeList(tmpMinimumList);
				}
			}
		}
		
		resetVisitedVertexList(VertexList);
		
		tmpAdjacentVertices = tmpAdjacentVertices->next;
	}
	
}

