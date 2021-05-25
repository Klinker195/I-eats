#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "headers/cliui.h"
#include "headers/utils.h"
#include "headers/datastructures.h"

int main(void) {

	User_t ConnectedUser;
	
	srand(time(NULL));
	
	/*
	TEST FETCHID
	
	int i = 0;
	for(i = 0; i < 10; i++) {
		printf("%u\n", fetchID());
	}
	*/
	
	/*
	TEST INSERIMENTO E CANCELLAZIONE DI UNA RISORSA
	
	Resource_t tmpResource;
	
	strcpy(tmpResource.Name, "ORGANI");
	tmpResource.SpecificWeight = 0.50;
	
	printf("\n %d\n\n", addResource(&tmpResource));
	
	system("pause");
	
	Node_t *ResourceHead = NULL;
	
	endInsResourcesFromFile(&ResourceHead);
	
	deleteResourceAtPosition(&ResourceHead, 1);
	
	FILE *IsleResourceData = fopen("./data/ResourcesList.isle", "w");
	
	if(!IsleResourceData) error(1000);
	
	writeListIntoResourcesFile(&ResourceHead, IsleResourceData);
	
	fclose(IsleResourceData);
	*/
	
	/*
	TEST VISUALIZZAZIONE RISORSE
	
	Node_t *ResourceHead = NULL;
	
	endInsResourcesFromFile(&ResourceHead);
	
	printResourcesList(&ResourceHead);
	*/
	
	/*
	TEST ADD VERTEX OLD
	
	Node_t *VertexList = NULL;
	Node_t *AdjacentVertices = NULL;
	Node_t *BridgeList = NULL;
	
	String *tmpData = malloc(sizeof(String));
	strcpy(*tmpData, "TestIsle 1");
	
	addVertex(&VertexList, AdjacentVertices, NULL, *tmpData);
	
	if(AdjacentVertices != NULL) freeList(&AdjacentVertices); 
	
	unsigned int *tmpUnsignedInt = (unsigned int *)1001u;
	endIns(&AdjacentVertices, tmpUnsignedInt);
	
	tmpData = malloc(sizeof(String));
	strcpy(*tmpData, "TestIsle 2");
	
	addVertex(&VertexList, AdjacentVertices, NULL, *tmpData);
	
	printVertexStringList(&VertexList);
	*/
	
	int Modality = isleStart(&ConnectedUser);
	
	if(Modality == 0) {
		isleDriver(&ConnectedUser);
	} else {
		isleCustomer(&ConnectedUser);
	}
	
	//system("pause");
	
	return 0;
}
