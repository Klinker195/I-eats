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

int printVertexList(Node_t **VertexList) {
	
	system("cls");
	
	Vertex_t *tmpVertex;
	Node_t *AdjacencyList;
	unsigned int *tmpID;
	
	int i = 0;
	
	printf(ANSI_COLOR_BRIGHTRED " [Elenco delle isole]\n");

	
	Node_t *tmp = *VertexList;
	
	while(tmp != NULL) {
		i++;
		tmpVertex = tmp->Data;
		
		printf(ANSI_COLOR_BRIGHTRED" +---------------------------------------------+\n");
		printf(" |   No. |   ID Isola   |      Nome Isola      |\n");
		printf(" +---------------------------------------------+\n"ANSI_COLOR_BRIGHTYELLOW);
		
		printf(ANSI_COLOR_BRIGHTRED " | " ANSI_COLOR_BRIGHTYELLOW "%4d. " ANSI_COLOR_BRIGHTRED "|" ANSI_COLOR_BRIGHTYELLOW " %12u "ANSI_COLOR_BRIGHTRED "|" ANSI_COLOR_BRIGHTYELLOW " %20s "ANSI_COLOR_BRIGHTRED"|\n", i, tmpVertex->ID, tmpVertex->IsleName);
		
		AdjacencyList = tmpVertex->AdjacentVertices;
		
		printf(" +---------------------------------------------+\n");
		printf(" |    "ANSI_COLOR_BRIGHTYELLOW"|"ANSI_COLOR_BRIGHTRED"  |             Collegamenti            |\n");
		printf(" +---------------------------------------------+\n"ANSI_COLOR_BRIGHTYELLOW);
		while(AdjacencyList != NULL) {
			tmpID = AdjacencyList->Data;
			printf(ANSI_COLOR_BRIGHTRED " | "ANSI_COLOR_BRIGHTYELLOW "   +"ANSI_COLOR_BRIGHTRED"---------------------------------"ANSI_COLOR_BRIGHTYELLOW"> %4u "ANSI_COLOR_BRIGHTRED"|\n", *tmpID);
			AdjacencyList = AdjacencyList->next;
		}
		
		printf(" +---------------------------------------------+\n\n" ANSI_COLOR_BRIGHTYELLOW);
		tmp = tmp->next;
	}
	
	return i;
}
/*
void printVertexStringList(Node_t **VertexList) {
	system("cls");
	
	Vertex_t *tmpVertex;
	Node_t *AdjacencyList;
	unsigned int *tmpID;
	
	int i = 0;
	
	Node_t *tmp = *VertexList;
	
	printf( "[Vertex List]");
	printf("\n\n");
	while(tmp != NULL) {
		tmpVertex = tmp->Data;
		
		printf(" - ID: %u | Isle Name: %s | Visited? %d", tmpVertex->ID, tmpVertex->IsleName, tmpVertex->Visited);
		
		AdjacencyList = tmpVertex->AdjacentVertices;
		
		while(AdjacencyList != NULL) {
			tmpID = AdjacencyList->Data;
			printf("\n      - %u", *tmpID);
			AdjacencyList = AdjacencyList->next;
		}
		
		printf("\n");
		
		tmp = tmp->next;
	}
	
	printf("\n\n");
}
*/
void printBridgeStringList(Node_t **BridgeList) {
	system("cls");
	
	Edge_t *tmpBridge;
	
	int i = 0;
	
	Node_t *tmp = *BridgeList;
	
	printf( "[Bridge List]");
	printf("\n\n");
	while(tmp != NULL) {
		tmpBridge = tmp->Data;
		
		printf(" - ID: %u%u | Max Weight: %lf", tmpBridge->VertexPair.x, tmpBridge->VertexPair.y, tmpBridge->MaxWeight);
		
		printf("\n");
		
		tmp = tmp->next;
	}
	
	printf("\n\n");
}

Vertex_t *fetchVertexFromID(Node_t **VertexList, unsigned int VertexID) {
	if(*VertexList == NULL) return NULL;
	
	Vertex_t *tmpVertex = (*VertexList)->Data;
	
	if(VertexID == tmpVertex->ID) return tmpVertex;
	
	return fetchVertexFromID(&((*VertexList)->next), VertexID);
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

bool tryBridge(Node_t **BridgeList, IdPair_t *VertexIdPair, double TotalWeight) {
	if(*BridgeList == NULL) return false;
	
	Edge_t *tmpBridge;
	tmpBridge = (*BridgeList)->Data;
	
	if(VertexIdPair->x == tmpBridge->VertexPair.x && VertexIdPair->y == tmpBridge->VertexPair.y || VertexIdPair->y == tmpBridge->VertexPair.x && VertexIdPair->x == tmpBridge->VertexPair.y) {
		if(TotalWeight <= tmpBridge->MaxWeight) return true;
	}
	
	return tryBridge(&((*BridgeList)->next), VertexIdPair, TotalWeight);
}

int printResourcesList(Node_t **Head) {
	
	system("cls");
	
	Resource_t *tmpData;
	
	int i = 0;
	
	printf(ANSI_COLOR_BRIGHTRED " [Risorse esistenti]\n");
	printf(" +---------------------------------------------+\n");
	printf(" |   No. |     Nome risorsa     |     Peso     |\n");
	printf(" +---------------------------------------------+\n"ANSI_COLOR_BRIGHTYELLOW);
	
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

int printOrderRecapList(Node_t **Head) {
	
	Resource_t *tmpData;
	
	int i = 0;
	
	printf(ANSI_COLOR_BRIGHTRED " [Riepilogo ordine]\n");
	printf(" +--------------------------------------------------+\n");
	printf(" |   No. |     Nome risorsa     |     Quantita'     |\n");
	printf(" +--------------------------------------------------+\n"ANSI_COLOR_BRIGHTYELLOW);
	
	Node_t *tmp = *Head;
	
	while(tmp != NULL) {
		i++;
		tmpData = tmp->Data;
		
		printf(ANSI_COLOR_BRIGHTRED " | " ANSI_COLOR_BRIGHTYELLOW "%4d. " ANSI_COLOR_BRIGHTRED "|" ANSI_COLOR_BRIGHTYELLOW " %20s "ANSI_COLOR_BRIGHTRED "|" ANSI_COLOR_BRIGHTYELLOW " %17d "ANSI_COLOR_BRIGHTRED"|\n", i, tmpData->Name, tmpData->Quantity);
		printf(" +--------------------------------------------------+\n"ANSI_COLOR_BRIGHTYELLOW);
		tmp = tmp->next;
	}
	
	return i;
}

void endInsVehicleOwnerFromFile(Node_t **Head) {
	
	FILE *IsleVehicleOwners = fopen("./data/VehiclesCFs.isle", "r");
	
	if(!IsleVehicleOwners) {
		fclose(IsleVehicleOwners);
		IsleVehicleOwners = fopen("./data/VehiclesCFs.isle", "w");
		fclose(IsleVehicleOwners);
		IsleVehicleOwners = fopen("./data/VehiclesCFs.isle", "r");
	}
	
	if(!IsleVehicleOwners) error(1000);
	
	fseek(IsleVehicleOwners, 0L, SEEK_END);
	long size = ftell(IsleVehicleOwners);
	
	rewind(IsleVehicleOwners);
	
	String tmpModel;
	Vehicle_t *tmpVehicle;
	User_t *VehicleOwner;
	Node_t *Vehicles = NULL;
	
	endInsVehiclesFromFile(&Vehicles);
	
	if(size != 0) {
		while(!feof(IsleVehicleOwners)) {
			VehicleOwner = malloc(sizeof(User_t));
			fscanf(IsleVehicleOwners, "%256s %256s\n", VehicleOwner->CF, tmpModel);
			tmpVehicle = fetchVehicleFromModel(&Vehicles, tmpModel);
			strcpy(VehicleOwner->Vehicle.Model, tmpVehicle->Model);
			VehicleOwner->Vehicle.Weight = tmpVehicle->Weight;
			endIns(Head, VehicleOwner);
		}
	}
	
	freeList(&Vehicles);
	
	fclose(IsleVehicleOwners);
}

void endInsVehiclesFromFile(Node_t **Head) {
	
	FILE *IsleVehicleData = fopen("./data/VehiclesList.isle", "r");
	
	if(!IsleVehicleData) {
		fclose(IsleVehicleData);
		IsleVehicleData = fopen("./data/VehiclesList.isle", "w");
		fclose(IsleVehicleData);
		IsleVehicleData = fopen("./data/VehiclesList.isle", "r");
	}
	
	if(!IsleVehicleData) error(1000);
	
	fseek(IsleVehicleData, 0L, SEEK_END);
	long size = ftell(IsleVehicleData);
	
	rewind(IsleVehicleData);
	
	Vehicle_t *tmpVehicle;
	
	if(size != 0) {
		while(!feof(IsleVehicleData)) {
			tmpVehicle = malloc(sizeof(Vehicle_t));
			fscanf(IsleVehicleData, "%s %lf\n", tmpVehicle->Model, &tmpVehicle->Weight);
			endIns(Head, tmpVehicle);
		}
	}
	
	fclose(IsleVehicleData);
}

void endInsBridgesFromFile(Node_t **Head) {
	
	FILE *IsleExistingBridges = fopen("./data/islands/ExistingBridges.isle", "r");
	
	if(!IsleExistingBridges) {
		fclose(IsleExistingBridges);
		IsleExistingBridges = fopen("./data/islands/ExistingBridges.isle", "w");
		fclose(IsleExistingBridges);
		IsleExistingBridges = fopen("./data/islands/ExistingBridges.isle", "r");
	}
	
	if(!IsleExistingBridges) error(1000);
	
	fseek(IsleExistingBridges, 0L, SEEK_END);
	long size = ftell(IsleExistingBridges);
	
	rewind(IsleExistingBridges);
	
	Edge_t *tmpEdge;
	
	if(size != 0) {
		while(!feof(IsleExistingBridges)) {
			tmpEdge = malloc(sizeof(Edge_t));
			fscanf(IsleExistingBridges, "%u %u %lf\n", &tmpEdge->VertexPair.x, &tmpEdge->VertexPair.y, &tmpEdge->MaxWeight);
			endIns(Head, tmpEdge);
		}
	}
	
	fclose(IsleExistingBridges);
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

bool searchInt(Node_t **Head, int RequestedInteger) {
	
	if(*Head == NULL) return false;
	
	int *tmpInt = (*Head)->Data;
	
	if(RequestedInteger == *tmpInt) {
		return true;
	}
	
	return searchInt(&((*Head)->next), RequestedInteger);
}

Vehicle_t *fetchVehicleFromModel(Node_t **Head, String Model) {
	if(*Head == NULL) return NULL;
	
	Vehicle_t *tmpVehicle = (*Head)->Data;
	
	if(strcmp(Model, tmpVehicle->Model) == 0) return tmpVehicle;
	
	return fetchVehicleFromModel(&((*Head)->next), Model);
}

Vertex_t *_fetchVertexAtPosition(Node_t **Head, int Pos, int CurrentPos) {
	
	if(*Head == NULL) return NULL;
	
	if(Pos == CurrentPos) {
		Vertex_t *tmpVertex = malloc(sizeof(Vertex_t));
		tmpVertex = (*Head)->Data;
		return tmpVertex;
	}
	
	return _fetchVertexAtPosition(&((*Head)->next), Pos, CurrentPos + 1);
}

Vertex_t *fetchVertexAtPosition(Node_t **Head, int Pos) {
	return _fetchVertexAtPosition(Head, Pos, 1);
}

Resource_t *_fetchResourceAtPosition(Node_t **Head, int Pos, int CurrentPos) {
	
	if(*Head == NULL) return NULL;
	
	if(Pos == CurrentPos) {
		Resource_t *tmpResource = malloc(sizeof(Resource_t));
		tmpResource = (*Head)->Data;
		return tmpResource;
	}
	
	return _fetchResourceAtPosition(&((*Head)->next), Pos, CurrentPos + 1);
}

Resource_t *fetchResourceAtPosition(Node_t **Head, int Pos) {
	return _fetchResourceAtPosition(Head, Pos, 1);
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

void writeListIntoVehicleOwnersFile(Node_t **List, FILE *IsleVehicleOwners) {
	if(*List == NULL) return;

	Node_t *Next = (*List)->next;
	User_t *tmpUser = (*List)->Data;
	
	fprintf(IsleVehicleOwners, "%s %s\n", tmpUser->CF, tmpUser->Vehicle.Model);
	
	writeListIntoVehicleOwnersFile(&Next, IsleVehicleOwners);
}

void writeListIntoResourcesFile(Node_t **List, FILE *IsleResourceData) {
	if(*List == NULL) return;

	Node_t *Next = (*List)->next;
	Resource_t *tmpResource = (*List)->Data;
	
	fprintf(IsleResourceData, "%s %lf\n", tmpResource->Name, tmpResource->SpecificWeight);
	
	writeListIntoResourcesFile(&Next, IsleResourceData);
}

void _writeListIntoOrderFile(Node_t **List, String UserCF, unsigned int VertexID, FILE *IsleOrderData, int Position) {
	if(*List == NULL) return;

	Node_t *Next = (*List)->next;
	Resource_t *tmpResource = (*List)->Data;

	if(Position == 0) {
		fprintf(IsleOrderData, "%s\n%d\n", UserCF, VertexID);
	}
	
	fprintf(IsleOrderData, "%s %d\n", tmpResource->Name, tmpResource->Quantity);
	
	if(Next == NULL) {
		fprintf(IsleOrderData, "-\n", tmpResource->Name, tmpResource->Quantity);
	}
	
	_writeListIntoOrderFile(&Next, UserCF, VertexID, IsleOrderData, Position + 1);
}

void writeListIntoOrderFile(Node_t **List, String UserCF, unsigned int VertexID, FILE *IsleOrderData) {
	_writeListIntoOrderFile(List, UserCF, VertexID, IsleOrderData, 0);
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


