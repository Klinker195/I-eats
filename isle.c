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
	
	// TESTING DI DEBUG
	/*
	Vertex_t *tmprint=NULL;
	Node_t *tml;
	int l = 0;
	char P[7] = "Pippo";
    Node_t *VertexList=NULL, *AdjacentVertices=NULL, *BridgeList=NULL; 
	void *Data=NULL;
	
	VertexList= malloc(sizeof(Node_t));
	VertexList->Data=NULL;
	VertexList->Data=NULL;
	AdjacentVertices= malloc(sizeof(Node_t));
	AdjacentVertices->Data=NULL;
	AdjacentVertices->next=NULL;
	BridgeList= malloc(sizeof(Node_t));
    BridgeList->Data=NULL;
    BridgeList->next=NULL;
	*/

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
						printf(" Inserisci il tuo codice fiscale: ");
						gets(User.CF);

						for(i = 0; i < strlen(User.CF); i++) {
							User.CF[i] = toupper(User.CF[i]);
						}

						if(strlen(User.CF) != 16 || !checkCFValidity(User.CF)) {
							printf("\n\n Errore: Il CF non e' valido.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(" Login fallito, reindirizzamento al menu' principale...");
							sleep(3);
							continue;
						}

						printf("\n");
						printf(" Inserisci la tua password: ");
						gets(User.Password);

						if(strlen(User.Password) < 1) {
							printf("\n\n Errore: La password non e' valida.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");

							printf("\n\n");
							printf(" Login fallito, reindirizzamento al menu' principale...");
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
							printf(" Login fallito, reindirizzamento al menu' principale...");
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
						printf(" Inserisci il tuo codice fiscale: ");
						gets(User.CF);

						for(i = 0; i < strlen(User.CF); i++) {
							User.CF[i] = toupper(User.CF[i]);
						}

						if(strlen(User.CF) != 16 || !checkCFValidity(User.CF)) {
							printf("\n\n Errore: Il CF non e' valido.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(" Login fallito, reindirizzamento al menu' principale...");
							sleep(3);
							continue;
						}

						printf("\n");
						printf(" Inserisci la tua password: ");
						gets(User.Password);

						if(strlen(User.Password) < 1) {
							printf("\n\n Errore: La password non e' valida.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");

							printf("\n\n");
							printf(" Login fallito, reindirizzamento al menu' principale...");
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
							printf(" Login fallito, reindirizzamento al menu' principale...");
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
						printf(" Inserisci la chiave di sicurezza: ");
						gets(intArg);

						tmpAdminKey = validateAtoi(intArg);

						if(tmpAdminKey != adminKey) {
							printf("\n\n Errore: La chiave di sicurezza non e' valida.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(" Registrazione fallita, reindirizzamento al menu' principale...");
							sleep(3);
							break;
						}
						
						printf("\n");
						printf(" Inserisci il tuo codice fiscale: ");
						gets(User.CF);

						for(i = 0; i < strlen(User.CF); i++) {
							User.CF[i] = toupper(User.CF[i]);
						}

						if(strlen(User.CF) != 16 || !checkCFValidity(User.CF)) {
							printf("\n\n Errore: Il CF non e' valido.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(" Registrazione fallita, reindirizzamento al menu' principale...");
							sleep(3);
							continue;
						}

						printf("\n");
						printf(" Inserisci la tua password: ");
						gets(verifyPassword);

						if(strlen(verifyPassword) < 1) {
							printf("\n\n Errore: La password non e' valida.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(" Registrazione fallita, reindirizzamento al menu' principale...");
							sleep(3);
							continue;
						}

						printf("\n");
						printf(" Verifica la tua password: ");
						gets(User.Password);
						
						// Registration driver 
						
						if(strcmp(verifyPassword, User.Password) == 0 && driverRegistration(User)) {
							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(" Registrazione riuscita, reindirizzamento al menu' principale...");
							sleep(2);
						} else {
							
							if(strcmp(verifyPassword, User.Password) != 0) {
							printf("\n\n Errore: Le due password inserite devono coincidere.");
							}

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(" Registrazione fallita, reindirizzamento al menu' principale...");
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
						printf(" Inserisci il tuo codice fiscale: ");
						gets(User.CF);

						for(i = 0; i < strlen(User.CF); i++) {
							User.CF[i] = toupper(User.CF[i]);
						}

						if(strlen(User.CF) != 16 || !checkCFValidity(User.CF)) {
							printf("\n\n Errore: Il CF non e' valido.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(" Registrazione fallita, reindirizzamento al menu' principale...");
							sleep(3);
							break;
						}

						printf("\n");
						printf(" Inserisci la tua password: ");
						gets(verifyPassword);

						if(strlen(verifyPassword) < 1) {
							printf("\n\n Errore: La password non e' valida.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(" Registrazione fallita, reindirizzamento al menu' principale...");
							sleep(3);
							break;
						}
						printf("\n");
						printf(" Verifica la tua password: ");
						gets(User.Password);
						
						// Registration customer 
						
						if(strcmp(verifyPassword, User.Password) == 0 && customerRegistration(User)) {
							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(" Registrazione riuscita, reindirizzamento al menu' principale...");
							sleep(2);
						} else {

							if(strcmp(verifyPassword, User.Password) != 0) {
								printf("\n\n Errore: Le due password inserite devono coincidere.");
							}

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(" Registrazione fallita, reindirizzamento al menu' principale...");
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
				// Option B
				break;
			case 2:
				exit(EXIT_SUCCESS);
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

	do {

		system("MODE 120,55");

		menuChoice = getVerticalInput(CustomerChoiceList, CUSTOMERCHOICELIST_SIZE, printCustomerChoice);
		
		switch(menuChoice) {
			case 0:
				isleCustomerPlaceOrder(ConnectedUser, ResourcesList);
				break;
			case 1:
				exit(EXIT_SUCCESS);
				break;
		}

	} while(!exitCheck);

	return;
}

// TODO: CustomerPlaceOrder da rifinire
void isleCustomerPlaceOrder(User_t *ConnectedUser, Node_t *ResourcesList) {
	
	if(!ResourcesList) {
		system("cls");
		printf("\n\n");
		printf(" Errore: Nessuna risorsa disponibile, riprovare...");
		sleep(3);
		return;
	}
	
	String intArg;
	
	int maxNum = printResourcesList(&ResourcesList);

	int numChoice = 0;

	int valueChoice = 0;

	bool numChoiceCheck = false;
	
	Node_t *SelectedNumbers = NULL;
	
	Node_t *Order = NULL;
	
	do {
		
		system("cls");
		printResourcesList(&ResourcesList);
		// print riepilogo ordine
		
		printf("\n\n");
		printf(" Inserisci il numero relativo all'item che vuoi ordinare (0 per concludere): ");
		gets(intArg);

		numChoice = validateAtoi(intArg);

		if(numChoice < 0 || numChoice > maxNum /* && !searchInt(&SelectedNumbers) */) {
			printf("\n\n");
			if(numChoice < 0 || numChoice) {
				printf(" Errore: Numero selezionato non valido, riprovare...");
				sleep(1);
			} else {
				printf(" Errore: Prodotto gia' selezionato, riprovare...");
				sleep(1);
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
			// Creazione Resource in malloc da inserire nella lista ordine, avrà come nome risorsa quello della risorsa alla posizione scelta dall'utente, stessa cosa per la quantità
			// endIns della risorsa in lista Order.
			endIns(&SelectedNumbers, &numChoice);
		}
		
		printf("\n\n");
		printf(" +-------------------------------------------------------------------------------------+");
	
	} while(!numChoiceCheck);
}

bool addResource(Resource_t *Resource, Node_t *ResourceList) {
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
		endIns(&ResourceList, Resource);
		return true;
	} else {
		fclose(IsleResourceData);
		return false;
	}

	fclose(IsleResourceData);
	return false;
}



