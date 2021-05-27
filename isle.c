#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "headers/cliui.h"
#include "headers/utils.h"
#include "headers/isle.h"
#include "headers/datastructures.h"


int isleStart(User_t *CurrentUser) {

	int i = 0;

	char clearBuffer;

	int startupChoice;
	int loginRegistrationChoice;

	bool loginDone = false;
	bool registrationDone = false;

	String intArg;

	String verifyPassword;

	User_t User;

	do {

		system("MODE 120,55");

		startupChoice = getVerticalInput(StartupChoiceList, STARTUPCHOICELIST_SIZE, printMainMenu);

		switch(startupChoice) {
			case 0:

				loginRegistrationChoice = getVerticalInput(LoginRegistrationChoiceList, LOGINREGISTRATIONCHOICELIST_SIZE, printLoginChoice);

				switch(loginRegistrationChoice) {
					case 0:

						system("cls");

						/*
						ASCII Art Style = Doom
						Effettuata sul sito: https://patorjk.com/software/taag/
						*/

						printf(ANSI_COLOR_BRIGHTRED" +--------------------------------------+\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"    _                    _            "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |                  (_)           "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |      ___    __ _  _  _ __      "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |     / _ \\  / _` || || '_ \\     "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |____| (_) || (_| || || | | |    "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   \\_____/ \\___/  \\__, ||_||_| |_|    "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"                   __/ |              "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"                  |___/               "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" +--------------------------------------+\n"ANSI_COLOR_BRIGHTYELLOW);

						printf("\n\n");
						printf(ANSI_COLOR_BRIGHTYELLOW" Inserisci il tuo codice fiscale: ");
						gets(User.CF);

						for(i = 0; i < strlen(User.CF); i++) {
							User.CF[i] = toupper(User.CF[i]);
						}

						if(strlen(User.CF) != 16 || !checkCFValidity(User.CF)) {
							printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Errore: Il CF non e' valido.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Login fallito, reindirizzamento al menu' principale...");
							sleep(3);
							continue;
						}

						printf("\n");
						printf(ANSI_COLOR_BRIGHTYELLOW" Inserisci la tua password: ");
						gets(User.Password);

						if(strlen(User.Password) < 1) {
							printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Errore: La password non e' valida.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Login fallito, reindirizzamento al menu' principale...");
							sleep(3);
							continue;
						}
						
						// Login driver
						
						if(driverLogin(&User))  {
							loginDone = true;
							*CurrentUser = User;
							return 0;
						} 
						
						 else {
							strcpy(User.CF, "");
							strcpy(User.Password, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Login fallito, reindirizzamento al menu' principale...");
							sleep(2);
						}
						
						break;
					case 1:
						system("cls");

						/*
						ASCII Art Style = Doom
						Effettuata sul sito: https://patorjk.com/software/taag/
						*/

						printf(ANSI_COLOR_BRIGHTRED" +--------------------------------------+\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"    _                    _            "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |                  (_)           "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |      ___    __ _  _  _ __      "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |     / _ \\  / _` || || '_ \\     "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |____| (_) || (_| || || | | |    "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   \\_____/ \\___/  \\__, ||_||_| |_|    "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"                   __/ |              "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"                  |___/               "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" +--------------------------------------+\n"ANSI_COLOR_BRIGHTYELLOW);

						printf("\n\n");
						printf(ANSI_COLOR_BRIGHTYELLOW" Inserisci il tuo codice fiscale: ");
						gets(User.CF);

						for(i = 0; i < strlen(User.CF); i++) {
							User.CF[i] = toupper(User.CF[i]);
						}

						if(strlen(User.CF) != 16 || !checkCFValidity(User.CF)) {
							printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Errore: Il CF non e' valido.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Login fallito, reindirizzamento al menu' principale...");
							sleep(3);
							continue;
						}

						printf("\n");
						printf(ANSI_COLOR_BRIGHTYELLOW" Inserisci la tua password: ");
						gets(User.Password);

						if(strlen(User.Password) < 1) {
							printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Errore: La password non e' valida.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Login fallito, reindirizzamento al menu' principale...");
							sleep(3);
							continue;
						}
						
						//Login customer
						
						if(customerLogin(&User))  {
							loginDone = true;
							*CurrentUser = User;
							return 1;
						} else {
							strcpy(User.CF, "");
							strcpy(User.Password, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Login fallito, reindirizzamento al menu' principale...");
							sleep(2);
						}
						
						break;
					default:

						break;
				}
				break;
			case 1:

				loginRegistrationChoice = getVerticalInput(LoginRegistrationChoiceList, LOGINREGISTRATIONCHOICELIST_SIZE, printRegistrationChoice);

				switch(loginRegistrationChoice) {
					case 0:

						system("cls");

						/*
						ASCII Art Style = Doom
						Effettuata sul sito: https://patorjk.com/software/taag/
						*/

						printf(ANSI_COLOR_BRIGHTRED" +----------------------------------------------------+\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   ______               _       _                   "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | ___ \\             (_)     | |                  "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |_/ /  ___   __ _  _  ___ | |_   ___  _ __     "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   |    /  / _ \\ / _` || |/ __|| __| / _ \\| '__|    "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |\\ \\ |  __/| (_| || |\\__ \\| |_ |  __/| |       "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   \\_| \\_| \\___| \\__, ||_||___/ \\__| \\___||_|       "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"                  __/ |                             "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"                 |___/                              "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" +----------------------------------------------------+\n"ANSI_COLOR_BRIGHTYELLOW);
					
						int tmpAdminKey;

						printf("\n\n");
						printf(ANSI_COLOR_BRIGHTYELLOW" Inserisci la chiave di sicurezza: ");
						gets(intArg);

						tmpAdminKey = validateAtoi(intArg);

						if(tmpAdminKey != adminKey) {
							printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Errore: La chiave di sicurezza non e' valida.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Registrazione fallita, reindirizzamento al menu' principale...");
							sleep(3);
							break;
						}
						
						printf("\n");
						printf(ANSI_COLOR_BRIGHTYELLOW" Inserisci il tuo codice fiscale: ");
						gets(User.CF);

						for(i = 0; i < strlen(User.CF); i++) {
							User.CF[i] = toupper(User.CF[i]);
						}

						if(strlen(User.CF) != 16 || !checkCFValidity(User.CF)) {
							printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Errore: Il CF non e' valido.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Registrazione fallita, reindirizzamento al menu' principale...");
							sleep(3);
							continue;
						}

						printf("\n");
						printf(ANSI_COLOR_BRIGHTYELLOW" Inserisci la tua password: ");
						gets(verifyPassword);

						if(strlen(verifyPassword) < 1) {
							printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Errore: La password non e' valida.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Registrazione fallita, reindirizzamento al menu' principale...");
							sleep(3);
							continue;
						}

						printf("\n");
						printf(ANSI_COLOR_BRIGHTYELLOW" Verifica la tua password: ");
						gets(User.Password);
						
						// Registration driver 
						
						if(strcmp(verifyPassword, User.Password) == 0 && driverRegistration(User)) {
							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Registrazione riuscita, reindirizzamento al menu' principale...");
							sleep(2);
						} else {
							
							if(strcmp(verifyPassword, User.Password) != 0) {
							printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Errore: Le due password inserite devono coincidere.");
							}

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Registrazione fallita, reindirizzamento al menu' principale...");
							sleep(3);
						}
						
						break;
					case 1:

						system("cls");

						/*
						ASCII Art Style = Doom
						Effettuata sul sito: https://patorjk.com/software/taag/
						*/

						printf(ANSI_COLOR_BRIGHTRED" +----------------------------------------------------+\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   ______               _       _                   "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | ___ \\             (_)     | |                  "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |_/ /  ___   __ _  _  ___ | |_   ___  _ __     "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   |    /  / _ \\ / _` || |/ __|| __| / _ \\| '__|    "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |\\ \\ |  __/| (_| || |\\__ \\| |_ |  __/| |       "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"   \\_| \\_| \\___| \\__, ||_||___/ \\__| \\___||_|       "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"                  __/ |                             "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" |"ANSI_COLOR_BRIGHTYELLOW"                 |___/                              "ANSI_COLOR_BRIGHTRED"|\n");
						printf(" +----------------------------------------------------+\n"ANSI_COLOR_BRIGHTYELLOW);
						
						printf("\n\n");
						printf(ANSI_COLOR_BRIGHTYELLOW" Inserisci il tuo codice fiscale: ");
						gets(User.CF);

						for(i = 0; i < strlen(User.CF); i++) {
							User.CF[i] = toupper(User.CF[i]);
						}

						if(strlen(User.CF) != 16 || !checkCFValidity(User.CF)) {
							printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Errore: Il CF non e' valido.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Registrazione fallita, reindirizzamento al menu' principale...");
							sleep(3);
							break;
						}

						printf("\n");
						printf(ANSI_COLOR_BRIGHTYELLOW" Inserisci la tua password: ");
						gets(verifyPassword);

						if(strlen(verifyPassword) < 1) {
							printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Errore: La password non e' valida.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Registrazione fallita, reindirizzamento al menu' principale...");
							sleep(3);
							break;
						}
						printf("\n");
						printf(ANSI_COLOR_BRIGHTYELLOW" Verifica la tua password: ");
						gets(User.Password);
						
						// Registration customer 
						
						if(strcmp(verifyPassword, User.Password) == 0 && customerRegistration(User)) {
							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Registrazione riuscita, reindirizzamento al menu' principale...");
							sleep(2);
						} else {

							if(strcmp(verifyPassword, User.Password) != 0) {
								printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Errore: Le due password inserite devono coincidere.");
							}

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(ANSI_COLOR_BRIGHTYELLOW" Registrazione fallita, reindirizzamento al menu' principale...");
							sleep(3);
							break;
						}
						
						break;
				}
				break;
				
				
			case 2:
				// TODO: Debug mode
				
			case 3:
				exit(0);
				break;
		}

	} while(!loginDone);

	return -1;
}


void isleDriver(User_t *ConnectedUser) {
	int menuChoice;

	bool exitCheck = false;

	do {

		system("MODE 120,55");

		menuChoice = getVerticalInput(DriverChoiceList, DRIVERCHOICELIST_SIZE, printDriverChoice);

		switch(menuChoice) {
			case 0:
				// Option A
				break;
			case 1:
				isleDriverChangeVehicleModel(ConnectedUser);
				break;
			case 2:
				exit(EXIT_SUCCESS);
				break;
		}

	} while(!exitCheck);

	return;
}

void isleDriverChangeVehicleModel(User_t *ConnectedUser) {
	int menuChoice;

	bool exitCheck = false;

	do {

		system("MODE 120,55");

		menuChoice = getVerticalInput(ChangeVehicleChoiceList, CHANGEVEHICLECHOICELIST_SIZE, printVehicleChangeChoice);

		switch(menuChoice) {
			case 0:
				swapUserVehicle(ConnectedUser, "Rotom-Autocarro");
				printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Veicolo correttamente cambiato in %s. Reindirizzamento al menu' principale...", ConnectedUser->Vehicle.Model);
				sleep(3);
				exitCheck = true;
				break;
			case 1:
				swapUserVehicle(ConnectedUser, "Rotom-Furgone");
				printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Veicolo correttamente cambiato in %s. Reindirizzamento al menu' principale...", ConnectedUser->Vehicle.Model);
				sleep(3);
				exitCheck = true;
				break;
			case 2:
				swapUserVehicle(ConnectedUser, "Rotom-Apecar");
				printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Veicolo correttamente cambiato in %s. Reindirizzamento al menu' principale...", ConnectedUser->Vehicle.Model);
				sleep(3);
				exitCheck = true;
				break;
			case 3:
				exitCheck = true;
				break;
		}

	} while(!exitCheck);

	return;
}

void isleCustomer(User_t *ConnectedUser) {
	int menuChoice;

	bool exitCheck = false;

	Node_t *ResourcesList = NULL;
	endInsResourcesFromFile(&ResourcesList);

	Node_t *BridgeList = NULL;
	endInsBridgesFromFile(&BridgeList);
	
	Node_t *VertexList = NULL;
	addVerticesAndEdgesFromFileData(&VertexList);

	do {

		system("MODE 120,55");

		menuChoice = getVerticalInput(CustomerChoiceList, CUSTOMERCHOICELIST_SIZE, printCustomerChoice);
		
		switch(menuChoice) {
			case 0:
				isleCustomerPlaceOrder(ConnectedUser, ResourcesList, VertexList);
				break;
			case 1:
				exit(EXIT_SUCCESS);
				break;
		}

	} while(!exitCheck);

	return;
}

bool isleCustomerPlaceOrder(User_t *ConnectedUser, Node_t *ResourcesList, Node_t *VertexList) {
	
	if(!ResourcesList) {
		system("cls");
		printf("\n\n");
		printf(ANSI_COLOR_BRIGHTYELLOW" Errore: Nessuna risorsa disponibile, riprovare...");
		sleep(3);
		return;
	}
	
	if(!checkOrderUniqueness(ConnectedUser->CF)) {
		system("cls");
		printf("\n\n");
		printf(ANSI_COLOR_BRIGHTYELLOW" Errore: E' gia' presente un ordine per il CF %s, reindirizzamento al menu' principale...", ConnectedUser->CF);
		sleep(3);
		return;
	}
	
	String intArg;
	
	int maxNum = printResourcesList(&ResourcesList);
	int numChoice = 0;
	int valueChoice = 0;
	bool numChoiceCheck = false;
	int *tmpInt;
	Vertex_t *tmpVertex;
	
	Node_t *SelectedNumbers = NULL;
	Node_t *Order = NULL;
	
	Resource_t *tmpResource;
	
	do {
		
		system("cls");
		printResourcesList(&ResourcesList);
		printOrderRecapList(&Order);
		
		printf("\n\n");
		printf(" Inserisci il numero relativo all'item che vuoi ordinare (0 per concludere): ");
		gets(intArg);

		numChoice = validateAtoi(intArg);

		if((numChoice < 0 || numChoice > maxNum) || searchInt(&SelectedNumbers, numChoice)) {
			printf("\n\n");
			if(numChoice < 0 || numChoice > maxNum) {
				printf(" Errore: Numero selezionato non valido, riprovare...");
				sleep(2);
			} else {
				printf(" Errore: Prodotto gia' selezionato, riprovare...");
				sleep(2);
			}
			continue;
		} else if(numChoice == 0) {
			numChoiceCheck = true;
			break;
		} 
		
		printf("\n\n");
		printf(" Inserisci la quantita' (max 10, 0 per concludere): ");
		gets(intArg);
		
		valueChoice = validateAtoi(intArg);
		
		if(valueChoice < 0 || valueChoice > 10) {
			printf("\n\n");
			printf(" Errore: Non e' possibile selezionare piu' di 10 item per tipo, riprovare...");
			sleep(2);
			continue;
		} else if(numChoice == 0) {
			numChoiceCheck = true;
		} else {
			tmpResource = fetchResourceAtPosition(&ResourcesList, numChoice);
			tmpResource->Quantity = valueChoice;
			
			endIns(&Order, tmpResource);
			
			tmpInt = malloc(sizeof(int));
			*tmpInt = numChoice;
			endIns(&SelectedNumbers, tmpInt);
		}
	
	} while(!numChoiceCheck);
	
	if(Order == NULL) {
		printf("\n\n Ordine annullato. Reindirizzamento al menu' precedente...");
		sleep(3);
		return false;
	}
	
	freeList(&SelectedNumbers);
	
	// TODO: Aggiungere richiesta destinazione
	
	bool DestinationChoiceMade = false;
	maxNum = printVertexList(&VertexList);
	numChoice = 0;
	
	do {
		
		system("cls");
		printVertexList(&VertexList);
		
		printf("\n\n");
		printf(" Inserisci il numero relativo all'isola dove consegnare le merci (0 per annullare): ");
		gets(intArg);

		numChoice = validateAtoi(intArg);

		if(numChoice < 0 || numChoice > maxNum) {
			printf("\n\n");
			printf(" Errore: Numero selezionato non valido, riprovare...");
			sleep(2);
			continue;
		} else if(numChoice == 0) {
			DestinationChoiceMade = true;
			break;
		} else {
			tmpVertex = fetchVertexAtPosition(&VertexList, numChoice);
			DestinationChoiceMade = true;
			break;
		}
	
	} while(!DestinationChoiceMade);
	
	if(numChoice = 0) {
		printf("\n\n Ordine annullato. Reindirizzamento al menu' precedente...");
		sleep(3);
		return false;
	}
	
	system("cls");
	
	printOrderRecapList(&Order);
	
	printf("\n\n ");
	system("pause");
	
	bool ChoiceMade = false;
	
	do {
		
		int Choice = getVerticalInput(ConfirmOrderChoiceList, CONFIRMORDERCHOICELIST_SIZE, printOrderConfirmationChoice);
		
		if(Choice == 0) {
			system("cls");
			printOrderRecapList(&Order);
			printf("\n\n ");
			system("pause");
		} else if(Choice == 1) {
			FILE *IsleOrderData = fopen("./data/IsleOrders.isle", "a");
			if(!IsleOrderData) error(1001);
			writeListIntoOrderFile(&Order, ConnectedUser->CF, tmpVertex->ID, IsleOrderData);
			fclose(IsleOrderData);
			freeList(&Order);
			printf(ANSI_COLOR_BRIGHTYELLOW "\n\n Ordine effettuato con successo. Reindirizzamento al menu' precedente...");
			sleep(3);
			return true;
		} else {
			freeList(&Order);
			printf(ANSI_COLOR_BRIGHTYELLOW "\n\n Ordine annullato. Reindirizzamento al menu' precedente...");
			sleep(3);
			return false;
		}
		
	} while(!ChoiceMade);
	
}

bool addResource(Resource_t *Resource, Node_t *ResourceList) {
	int i = 0;
	
	if(Resource->SpecificWeight == 0) {
		printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Errore: Peso non valido.");
		sleep(2);
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
			printf(ANSI_COLOR_BRIGHTYELLOW"\n\n Errore: Risorsa gia' esistente.");
			return false;
		}
	}
	
	fclose(IsleResourceData);
	
	IsleResourceData = fopen("./data/ResourcesList.isle", "a");
	
	if(!IsleResourceData) error(1000);
	
	if(fprintf(IsleResourceData, "%s %lf\n", Resource->Name, Resource->SpecificWeight) >= 0) {
		fclose(IsleResourceData);
		endIns(&ResourceList, Resource);
		return true;
	} else {
		fclose(IsleResourceData);
		return false;
	}

	fclose(IsleResourceData);
	return false;
}

void swapUserVehicle(User_t *ConnectedUser, String Model) {
	Node_t *VehicleList = NULL;
	
	endInsVehiclesFromFile(&VehicleList);
	
	Vehicle_t *tmpVehicle;
	tmpVehicle = fetchVehicleFromModel(&VehicleList, Model);
	
	strcpy(ConnectedUser->Vehicle.Model, tmpVehicle->Model);
	ConnectedUser->Vehicle.Weight = tmpVehicle->Weight;
	
	Node_t *VehicleOwnerList = NULL;
	endInsVehicleOwnerFromFile(&VehicleOwnerList);
	
	User_t *tmpUser;
	Node_t *tmpNode = VehicleOwnerList;
	
	while(tmpNode != NULL) {
		tmpUser = tmpNode->Data;
		if(strncmp(ConnectedUser->CF, tmpUser->CF, 16) == 0) {
			strcpy(tmpUser->Vehicle.Model, ConnectedUser->Vehicle.Model);
			tmpUser->Vehicle.Weight = ConnectedUser->Vehicle.Weight;
		}
		tmpNode = tmpNode->next;
	}
	
	FILE *IsleVehicleOwners = fopen("./data/VehiclesCFs.isle", "w");
	
	if(!IsleVehicleOwners) error(1000);
	
	writeListIntoVehicleOwnersFile(&VehicleOwnerList, IsleVehicleOwners);
	
	fclose(IsleVehicleOwners);
	
	freeList(&VehicleOwnerList);
	freeList(&VehicleList);
}

bool checkOrderUniqueness(String CF) {
	
	FILE *IsleOrdersData = fopen("./data/IsleOrders.isle", "r");
	
	if(!IsleOrdersData) {
		fclose(IsleOrdersData);
		IsleOrdersData = fopen("./data/IsleOrders.isle", "w");
		fclose(IsleOrdersData);
		IsleOrdersData = fopen("./data/IsleOrders.isle", "r");
	}
	
	if(!IsleOrdersData) error(1000);
	
	fseek(IsleOrdersData, 0L, SEEK_END);
	long size = ftell(IsleOrdersData);
	
	rewind(IsleOrdersData);
	
	String tmpCF;
	
	if(size != 0) {
		while(!feof(IsleOrdersData)) {
			fscanf(IsleOrdersData, "%s\n", tmpCF);
			if(strncmp(CF, tmpCF, 16) == 0) {
				fclose(IsleOrdersData);
				return false;
			}
		}
	}
	
	fclose(IsleOrdersData);
	return true;
}

