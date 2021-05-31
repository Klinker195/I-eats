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

void copyList(Node_t **Destination, Node_t **Source) {
	if(*Source == NULL) return;
	
	endIns(Destination, (*Source)->Data);
	
	return copyList(Destination, &((*Source)->next));
}

int printMinimumRouteList(Node_t **VertexList) {
	
	system("cls");
	
	Vertex_t *tmpVertex;
	Node_t *AdjacencyList;
	unsigned int *tmpID;
	
	int i = 0;
	
	printf(ANSI_COLOR_BRIGHTRED " [Percorso minimo da effettuare]\n");

	
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

int printOrderList(Node_t **OrderList) {
	
	system("cls");
	
	Order_t *tmpOrder;
	Node_t *ResourceList;
	Resource_t *tmpResource;
	
	int i = 1;
	
	printf(ANSI_COLOR_BRIGHTRED " [Elenco degli ordini]\n");
	
	Node_t *tmp = *OrderList;
	
	while(tmp != NULL) {
		tmpOrder = tmp->Data;
		
		printf(ANSI_COLOR_BRIGHTRED" +----------------------------------------------+\n");
		printf(" |   No. |   ID Isola   |      Richiedente      |\n");
		printf(" +----------------------------------------------+\n"ANSI_COLOR_BRIGHTYELLOW);
		
		printf(ANSI_COLOR_BRIGHTRED " | " ANSI_COLOR_BRIGHTYELLOW "%4d. " ANSI_COLOR_BRIGHTRED "|" ANSI_COLOR_BRIGHTYELLOW " %12u "ANSI_COLOR_BRIGHTRED "|" ANSI_COLOR_BRIGHTYELLOW " %21s "ANSI_COLOR_BRIGHTRED"|\n", i, tmpOrder->IsleID, tmpOrder->CF);
		
		ResourceList = tmpOrder->Resources;
		
		printf(" +----------------------------------------------+\n");
		printf(" |    "ANSI_COLOR_BRIGHTYELLOW"|"ANSI_COLOR_BRIGHTRED"  |   Quantita'  |        Risorsa        |\n");
		printf(" +----------------------------------------------+\n"ANSI_COLOR_BRIGHTYELLOW);
		while(ResourceList != NULL) {
			tmpResource = ResourceList->Data;
			printf(ANSI_COLOR_BRIGHTRED " | "ANSI_COLOR_BRIGHTYELLOW "   +"ANSI_COLOR_BRIGHTRED"-"ANSI_COLOR_BRIGHTYELLOW">"ANSI_COLOR_BRIGHTRED"|"ANSI_COLOR_BRIGHTYELLOW" %12d "ANSI_COLOR_BRIGHTRED"|"ANSI_COLOR_BRIGHTYELLOW" %21s "ANSI_COLOR_BRIGHTRED"|\n", tmpResource->Quantity, tmpResource->Name);
			ResourceList = ResourceList->next;
		}
		
		printf(ANSI_COLOR_BRIGHTRED" +----------------------------------------------+\n\n" ANSI_COLOR_BRIGHTYELLOW);
		i++;
		tmp = tmp->next;
	}
	
	return i;
}

int countOrderItems(Node_t **OrderItems) {
	if(*OrderItems == NULL) return 0;
	
	return 1 + countOrderItems(&((*OrderItems)->next));
}

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

void endInsOrderFromFile(Node_t **Head) {
	
	FILE *IsleOrderData = fopen("./data/IsleOrders.isle", "r");
	
	if(!IsleOrderData) {
		fclose(IsleOrderData);
		IsleOrderData = fopen("./data/IsleOrders.isle", "w");
		fclose(IsleOrderData);
		IsleOrderData = fopen("./data/IsleOrders.isle", "r");
	}
	
	if(!IsleOrderData) error(1000);
	
	fseek(IsleOrderData, 0L, SEEK_END);
	long size = ftell(IsleOrderData);
	
	rewind(IsleOrderData);
	
	Order_t *tmpOrder;
	Resource_t *tmpResource;
	int i = 0;
	
	if(size != 0) {
		while(!feof(IsleOrderData)) {
			tmpOrder = malloc(sizeof(Order_t));
			tmpOrder->Resources = NULL;
			fscanf(IsleOrderData, "%s\n%u\n%d\n", tmpOrder->CF, &tmpOrder->IsleID, &tmpOrder->ItemsQuantity);
			i = 0;
			while(!feof(IsleOrderData) && i != tmpOrder->ItemsQuantity) {
				tmpResource = malloc(sizeof(Resource_t));
				fscanf(IsleOrderData, "%s %d\n", tmpResource->Name, &tmpResource->Quantity);
				endIns(&(tmpOrder->Resources), tmpResource);
				i++;
			}
			endIns(Head, tmpOrder);
		}
	}
	
	fclose(IsleOrderData);
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

int countList(Node_t **Head) {
	if(*Head == NULL) return 0;

	return 1 + countList(&((*Head)->next));
}

Vertex_t *getRandomStartingVertex(Node_t **Head) {
	return fetchVertexAtPosition(Head, (rand() % countList(Head)) + 1);
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

Order_t *_fetchOrderAtPosition(Node_t **Head, int Pos, int CurrentPos) {
	
	if(*Head == NULL) return NULL;
	
	if(Pos == CurrentPos) {
		Order_t *tmpOrder = malloc(sizeof(Order_t));
		tmpOrder = (*Head)->Data;
		return tmpOrder;
	}
	
	return _fetchOrderAtPosition(&((*Head)->next), Pos, CurrentPos + 1);
}

Order_t *fetchOrderAtPosition(Node_t **Head, int Pos) {
	return _fetchOrderAtPosition(Head, Pos, 1);
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

void fetchAndSetSpecificWeightFromFile(Node_t **ResourceOrderList, FILE *IsleResourceData) {
	if(*ResourceOrderList == NULL) return;
	
	Resource_t buffResource;
	
	Resource_t *tmpResource = (*ResourceOrderList)->Data;
	
	while(!feof(IsleResourceData)) {
		fscanf(IsleResourceData, "%s %lf\n", buffResource.Name, &buffResource.SpecificWeight);
		if(strcmp(buffResource.Name, tmpResource->Name) == 0) {
			tmpResource->SpecificWeight = buffResource.SpecificWeight;
		}
	}
	
	rewind(IsleResourceData);
	
	fetchAndSetSpecificWeightFromFile(&((*ResourceOrderList)->next), IsleResourceData);
}

bool _deleteBridgeAtVertexID(Node_t **Head, unsigned int VertexID, int CurrentPos) {
	if(*Head == NULL) return false;
	
	Node_t *Next = (*Head)->next;
	
	Edge_t *tmpBridge = (*Head)->Data;
	
	if((tmpBridge->VertexPair.x == VertexID || tmpBridge->VertexPair.y == VertexID) && CurrentPos == 1) {
		free(*Head);
		*Head = Next;
		return true;
	}
	
	Edge_t *tmpNextBridge = Next->Data;
	
	if(tmpNextBridge->VertexPair.x == VertexID || tmpNextBridge->VertexPair.y == VertexID) {
		(*Head)->next = Next->next;
		free(Next);
		return true;
	}
	
	return _deleteBridgeAtVertexID(&Next, VertexID, CurrentPos + 1);
}

bool deleteBridgeAtVertexID(Node_t **Head, unsigned int VertexID) {
	return _deleteBridgeAtVertexID(Head, VertexID, 1);
}

bool _deleteIntAtVertexID(Node_t **Head, unsigned int VertexID, int CurrentPos) {
	if(*Head == NULL) return false;
	
	Node_t *Next = (*Head)->next;
	unsigned int *tmpInt = (*Head)->Data;
	
	if(*tmpInt == VertexID && CurrentPos == 1) {
		free(*Head);
		*Head = Next;
		return true;
	}
	
	unsigned int *tmpNextInt = Next->Data;
	
	if(*tmpNextInt == VertexID) {
		(*Head)->next = Next->next;
		free(Next);
		return true;
	}
	
	return _deleteIntAtVertexID(&Next, VertexID, CurrentPos + 1);
}

bool deleteIntAtVertexID(Node_t **Head, unsigned int VertexID) {
	return _deleteIntAtVertexID(Head, VertexID, 1);
}

bool deleteAdjacentVerticesAtVertexID(Node_t **Head, unsigned int VertexID) {
	if(*Head == NULL) return false;
	
	Node_t *Next = (*Head)->next;
	
	Vertex_t *tmpVertex = (*Head)->Data;
	
	deleteIntAtVertexID(&(tmpVertex->AdjacentVertices), VertexID);
	
	return deleteAdjacentVerticesAtVertexID(&Next, VertexID);
}

bool _deleteVertexAtPosition(Node_t **Head, int Pos, int CurrentPos) {
	if(*Head == NULL) return false;
	
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
	
	return _deleteVertexAtPosition(&((*Head)->next), Pos, CurrentPos + 1);
}

bool deleteVertexAtPosition(Node_t **Head, int Pos) {
	return _deleteVertexAtPosition(Head, Pos, 1);
}

bool _deleteOrderAtPosition(Node_t **Head, int Pos, int CurrentPos) {
	
	if(*Head == NULL) return false;
	
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
	
	return _deleteOrderAtPosition(&((*Head)->next), Pos, CurrentPos + 1);
}

bool deleteOrderAtPosition(Node_t **Head, int Pos) {
	return _deleteOrderAtPosition(Head, Pos, 1);
}

bool _deleteOrderAtCF(Node_t **Head, String UserCF, int CurrentPos) {
	if(*Head == NULL) return false;
	
	Node_t *Next = (*Head)->next;
	Order_t *tmpOrder = (*Head)->Data;
	
	if(strncmp(tmpOrder->CF, UserCF, 16) == 0 && CurrentPos == 1) {
		free(*Head);
		*Head = Next;
		return true;
	}
	
	Order_t *tmpNextOrder = Next->Data;
	
	if(strncmp(tmpNextOrder->CF, UserCF, 16) == 0) {
		(*Head)->next = Next->next;
		free(Next);
		return true;
	}
	
	return _deleteOrderAtCF(&Next, UserCF, CurrentPos + 1);
}

bool deleteOrderAtCF(Node_t **Head, String UserCF) {
	return _deleteOrderAtCF(Head, UserCF, 1);
}

bool _deleteResourceAtPosition(Node_t **Head, int Pos, int CurrentPos) {
	
	if(*Head == NULL) return false;
	
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

void _writeVertexListIntoIsleFolderAndFile(Node_t **List, FILE *IsleIslandsData) {
	if(*List == NULL) return;

	Node_t *Next = (*List)->next;
	Vertex_t *tmpVertex = (*List)->Data;
	Node_t *AdjacentVertices = tmpVertex->AdjacentVertices;
	unsigned int *tmpID;
	
	String StringID;
	
	itoa(tmpVertex->ID, StringID, 10);
	String FinalPath = "./data/islands/";
	strcat(FinalPath, StringID);
	strcat(FinalPath, ".isle");
	
	FILE* IsleSingleIsleData = fopen(FinalPath, "w");
	
	if(!IsleSingleIsleData) error(1000);
	
	fprintf(IsleSingleIsleData, "%s\n", tmpVertex->IsleName);
	
	while(AdjacentVertices != NULL) {
		tmpID = AdjacentVertices->Data;
		if(AdjacentVertices->next == NULL) {
			fprintf(IsleSingleIsleData, "%u", *tmpID);
		} else {
			fprintf(IsleSingleIsleData, "%u\n", *tmpID);
		}
		AdjacentVertices = AdjacentVertices->next;
	}
	
	fprintf(IsleIslandsData, "%u\n", tmpVertex->ID);
	
	fclose(IsleSingleIsleData);
	
	_writeVertexListIntoIsleFolderAndFile(&Next, IsleIslandsData);
}

void writeVertexListIntoIsleFolderAndFile(Node_t **List, FILE *IsleIslandsData) {
	removeAllIslandFiles(List);
	_writeVertexListIntoIsleFolderAndFile(List, IsleIslandsData);
}

void removeAllIslandFiles(Node_t **List) {
	if(*List == NULL) return;
	
	Node_t *Next = (*List)->next;
	Vertex_t *tmpVertex = (*List)->Data;
	
	String StringID;
	
	itoa(tmpVertex->ID, StringID, 10);
	String FinalPath = "./data/islands/";
	strcat(FinalPath, StringID);
	strcat(FinalPath, ".isle");
	
	remove(FinalPath);
	
	removeAllIslandFiles(&Next);
}

void writeBridgeListIntoBridgeFile(Node_t **List, FILE *IsleBridgeData) {
	if(*List == NULL) return;

	Node_t *Next = (*List)->next;
	Edge_t *tmpBridge = (*List)->Data;
	
	fprintf(IsleBridgeData, "%u %u %lf\n", tmpBridge->VertexPair.x, tmpBridge->VertexPair.y, tmpBridge->MaxWeight);
	
	writeBridgeListIntoBridgeFile(&Next, IsleBridgeData);
}

void writeOrderListIntoOrderFile(Node_t **List, FILE *IsleOrderData) {
	if(*List == NULL) return;

	Node_t *Next = (*List)->next;
	Order_t *tmpOrder = (*List)->Data;
	
	fprintf(IsleOrderData, "%s\n%u\n%d\n", tmpOrder->CF, tmpOrder->IsleID, tmpOrder->ItemsQuantity);
	
	Node_t *tmp;
	Resource_t *tmpResource;
	
	tmp = tmpOrder->Resources;
	int i = 0;
	
	while(tmp != NULL && i < tmpOrder->ItemsQuantity) {
		tmpResource = tmp->Data;
		fprintf(IsleOrderData, "%s %d\n", tmpResource->Name, tmpResource->Quantity);
		tmp = tmp->next;
		i++;
	}
	
	writeOrderListIntoOrderFile(&Next, IsleOrderData);
}

void _writeListIntoOrderFile(Node_t **List, String UserCF, unsigned int VertexID, int ItemsQuantity, FILE *IsleOrderData, int Position) {
	if(*List == NULL) return;

	Node_t *Next = (*List)->next;
	Resource_t *tmpResource = (*List)->Data;

	if(Position == 0) {
		fprintf(IsleOrderData, "%s\n%u\n%d\n", UserCF, VertexID, ItemsQuantity);
	}
	
	fprintf(IsleOrderData, "%s %d\n", tmpResource->Name, tmpResource->Quantity);
	
	_writeListIntoOrderFile(&Next, UserCF, VertexID, ItemsQuantity, IsleOrderData, Position + 1);
}

void writeListIntoOrderFile(Node_t **List, String UserCF, unsigned int VertexID, int ItemsQuantity, FILE *IsleOrderData) {
	_writeListIntoOrderFile(List, UserCF, VertexID, ItemsQuantity, IsleOrderData, 0);
}

double _calcTotalWeight(Node_t **ResourceList) {
	if(*ResourceList == NULL) return 0;
	
	Resource_t *tmpResource = (*ResourceList)->Data;
	
	return (tmpResource->Quantity * tmpResource->SpecificWeight) + _calcTotalWeight(&((*ResourceList)->next));
}

double calcTotalWeight(Vehicle_t Vehicle, Node_t **ResourceList) {
	return Vehicle.Weight + _calcTotalWeight(ResourceList);
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


