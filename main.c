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
#include "headers/debug.h"

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
	
	int Modality = isleStart(&ConnectedUser);
	
	if(Modality == 0) {
		isleDriver(&ConnectedUser);
	} else {
		isleCustomer(&ConnectedUser);
	}
	
	//system("pause");
	
	return 0;
}
