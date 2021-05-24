#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/utils.h"
#include "headers/datastructures.h"
#include "headers/cliui.h"

void headIns(Node_t **Head, void* Data) {
	
	Node_t *newNode = createNode(Data);
	
	newNode->next = *Head;
	*Head = newNode;
	
	return;
}

void _endIns(Node_t **Head, int Pos, void* Data) {
	
	Node_t *newNode;
	
	if(*Head == NULL) {
		if(Pos == 0) {
			newNode = createNode(Data);
			*Head = newNode;
		}
		return;
	}
	
	Node_t *tmp = *Head;
	
	_endIns(&(tmp->next), Pos + 1, Data);
	
	if(tmp->next == NULL) {
		newNode = createNode(Data);
		tmp->next = newNode;
	}
	
	return;
}

void endIns(Node_t **Head, void *Data) {
	_endIns(Head, 0, Data);
	return;
}

/*
int printPastAppointmentsList(Node_t **Head) {
	
	system("cls");
	
	FixedAppointment_t *tmpData;
	
	int i = 0;
	
	printf(ANSI_COLOR_CYAN " [Storico appuntamenti]\n");
	printf(" +-------------------------------------------------------------------------------------------------------+\n");
	printf(" |   No. |    Codice fiscale    |          Data          |          Orario          |     Positivita'    |\n");
	printf(" +-------------------------------------------------------------------------------------------------------+\n"ANSI_COLOR_RESET);
	
	Node_t *tmp = *Head;
	String tmpHour;
	
	while(tmp != NULL) {
		i++;
		tmpData = tmp->Data;
		
		if(tmpData->Hour == Morning) {
			strcpy(tmpHour, "Mattina");
		} else if(tmpData->Hour == Afternoon) {
			strcpy(tmpHour, "Pomeriggio");
		} else {
			strcpy(tmpHour, "Sera");
		}
		
		printf(ANSI_COLOR_CYAN " | " ANSI_COLOR_RESET "%4d. " ANSI_COLOR_CYAN "|" ANSI_COLOR_RESET " %20s "ANSI_COLOR_CYAN"|"ANSI_COLOR_RESET"       %4d/%2d/%2d       "ANSI_COLOR_CYAN"|"ANSI_COLOR_RESET"%15s           "ANSI_COLOR_CYAN"|"ANSI_COLOR_RESET"%14s      "ANSI_COLOR_CYAN"|\n", i, tmpData->CF, tmpData->Date.Year, tmpData->Date.Month, tmpData->Date.Day, tmpHour, tmpData->isPositive ? "POSITIVO" : "NEGATIVO");
		printf(" +-------------------------------------------------------------------------------------------------------+\n" ANSI_COLOR_RESET);
		tmp = tmp->next;
	}
	
	return i;
}
*/

void printVertexStringList(Node_t **VertexList) {
	system("cls");
	
	Vertex_t *tmpVertex;
	String *tmpString;
	
	int i = 0;
	
	Node_t *tmp = *VertexList;
	
	printf( "[Vertex List]");
	printf("\n\n");
	while(tmp != NULL) {
		tmpVertex = tmp->Data;
		tmpString = tmpVertex->Data;
		
		printf(" - ID: %u | Isle Name: %s\n", tmpVertex->ID, *tmpString);
		tmp = tmp->next;
	}
	
	printf("\n\n");
	system("pause");
}

bool searchVertexID(Node_t **VertexList, unsigned int VertexID) {
	if(*VertexList == NULL) return false;
	
	Vertex_t *tmpVertex = (*VertexList)->Data;
	
	if(VertexID == tmpVertex->ID) return true;
	
	return searchVertexID(&((*VertexList)->next), VertexID);
}

bool searchBridge(Node_t **BridgeList, IdPair_t *VertexIdPair) {
	if(*BridgeList == NULL) return false;
	
	Edge_t *tmpBridge;
	tmpBridge = (*BridgeList)->Data;
	
	if(VertexIdPair->x == tmpBridge->VertexPair.x && VertexIdPair->y == tmpBridge->VertexPair.y || VertexIdPair->y == tmpBridge->VertexPair.x && VertexIdPair->x == tmpBridge->VertexPair.y) return true;
	
	return searchBridge(&((*BridgeList)->next), VertexIdPair);
}

int printResourcesList(Node_t **Head) {
	
	system("cls");
	
	Resource_t *tmpData;
	
	int i = 0;
	
	printf(ANSI_COLOR_BRIGHTRED " [Risorse esistenti]\n");
	printf(" +---------------------------------------------+\n");
	printf(" |   No. |     Nome risorsa     |     Peso     |\n");
	printf(" +------------------------------+--------------+\n"ANSI_COLOR_BRIGHTYELLOW);
	
	Node_t *tmp = *Head;
	
	while(tmp != NULL) {
		i++;
		tmpData = tmp->Data;
		
		printf(ANSI_COLOR_BRIGHTRED " | " ANSI_COLOR_BRIGHTYELLOW "%4d. " ANSI_COLOR_BRIGHTRED "|" ANSI_COLOR_BRIGHTYELLOW " %20s "ANSI_COLOR_BRIGHTRED "|" ANSI_COLOR_BRIGHTYELLOW " %9.2lf kg "ANSI_COLOR_BRIGHTRED"|\n", i, tmpData->Name, tmpData->SpecificWeight);
		printf(" +---------------------------------------------+\n" ANSI_COLOR_BRIGHTYELLOW);
		tmp = tmp->next;
	}
	
	return i;
}

void endInsResourcesFromFile(Node_t **Head) {
	
	FILE *IsleResourceData = fopen("./data/ResourcesList.isle", "r");
	
	if(!IsleResourceData) {
		fclose(IsleResourceData);
		IsleResourceData = fopen("./data/ResourcesList.isle", "w");
		fclose(IsleResourceData);
		IsleResourceData = fopen("./data/ResourcesList.isle", "r");
	}
	
	if(!IsleResourceData) error(1000);
	
	fseek(IsleResourceData, 0L, SEEK_END);
	long size = ftell(IsleResourceData);
	
	rewind(IsleResourceData);
	
	Resource_t *tmpResource;
	
	if(size != 0) {
		while(!feof(IsleResourceData)) {
			tmpResource = malloc(sizeof(Resource_t));
			fscanf(IsleResourceData, "%s %lf\n", tmpResource->Name, &tmpResource->SpecificWeight);
			tmpResource->Quantity = 1;
			endIns(Head, tmpResource);
		}
	}
	
	fclose(IsleResourceData);
}

bool _deleteResourceAtPosition(Node_t **Head, int Pos, int CurrentPos) {
	
	if(*Head == NULL) return NULL;
	
	Node_t *Next = (*Head)->next;
	
	if(Pos == CurrentPos && CurrentPos == 1) {
		free(*Head);
		*Head = Next;
		return true;
	}
	
	if(Pos == (CurrentPos + 1)) {
		(*Head)->next = Next->next;
		free(Next);
		return true;
	}
	
	return _deleteResourceAtPosition(&((*Head)->next), Pos, CurrentPos + 1);
}

bool deleteResourceAtPosition(Node_t **Head, int Pos) {
	return _deleteResourceAtPosition(Head, Pos, 1);
}

void writeListIntoResourcesFile(Node_t **List, FILE *IsleResourceData) {
	if(*List == NULL) return;

	Node_t *Next = (*List)->next;
	Resource_t *tmpResource = (*List)->Data;
	
	fprintf(IsleResourceData, "%s %lf\n", tmpResource->Name, tmpResource->SpecificWeight);
	
	writeListIntoResourcesFile(&Next, IsleResourceData);
}


void _freeList(Node_t **Head) {
	
	if(*Head == NULL) return;
	
	Node_t *tmp = *Head;
	
	_freeList(&(tmp->next));
	
	free(tmp);

}

void freeList(Node_t **Head) {
	_freeList(Head);
	*Head = NULL;
	return;
}


