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


