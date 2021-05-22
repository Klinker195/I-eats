#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "headers/utils.h"
#include "headers/debug.h"
#include "headers/cliui.h"

bool addResource(Resource_t *Resource) {
	int i = 0;
	
	if(Resource->SpecificWeight == 0) {
		printf("\n\n Errore: Peso non valido.");
		return false;
	}
	
	for(i = 0; i < strlen(Resource->Name); i++) {
		Resource->Name[i] = toupper(Resource->Name[i]);
	}
	
	FILE *IsleResourceData = fopen("./data/ResourcesList.isle", "r+");

	if(!IsleResourceData) {
		fclose(IsleResourceData);
		IsleResourceData = fopen("./data/ResourcesList.isle", "w");
		fclose(IsleResourceData);
		IsleResourceData = fopen("./data/ResourcesList.isle", "r+");
	}

	if(!IsleResourceData) error(1000);
	
	String tmpResourceName;
	double buff;

	while(!feof(IsleResourceData)) {
		fscanf(IsleResourceData, "%s %lf", tmpResourceName, &buff);
		if(strcmp(tmpResourceName, Resource->Name) == 0) {
			fclose(IsleResourceData);
			printf("\n\n Errore: Risorsa gia' esistente.");
			return false;
		}
	}
	
	fclose(IsleResourceData);
	
	IsleResourceData = fopen("./data/ResourcesList.isle", "a");
	
	if(!IsleResourceData) error(1000);
	
	if(fprintf(IsleResourceData, "%s %lf\n", Resource->Name, Resource->SpecificWeight) >= 0) {
		fclose(IsleResourceData);
		return true;
	} else {
		fclose(IsleResourceData);
		return false;
	}

	fclose(IsleResourceData);
	return false;
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

