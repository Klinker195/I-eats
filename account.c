#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "headers/account.h"

bool customerLogin(User_t *User) {
	FILE *IsleCustomerData = NULL;
	User_t tmpUser;	
	
	IsleCustomerData = fopen("./data/CustomerLoginData.isle", "r");

	if(!IsleCustomerData) {
		fclose(IsleCustomerData);	
		IsleCustomerData = fopen("./data/CustomerLoginData.isle", "w");
		fclose(IsleCustomerData);
		IsleCustomerData = fopen("./data/CustomerLoginData.isle", "r");
	}
	
	if(!IsleCustomerData) error(1000);	
	
	int i = 0;

	for(i = 0; i < strlen(User->CF); i++) {
		User->CF[i] = toupper(User->CF[i]);
	}
	
	while(!feof(IsleCustomerData)) {
		fscanf(IsleCustomerData, "%s %s", tmpUser.CF, tmpUser.Password);
		if(strcmp(tmpUser.CF, User->CF) == 0) {
			if(strcmp(tmpUser.Password, User->Password) == 0) {
				fclose(IsleCustomerData);
				return true;
			}
			break;
		}
	}
	
	fclose(IsleCustomerData);
	
	if(strcmp(tmpUser.CF, User->CF) == 0 && strcmp(tmpUser.Password, User->Password) != 0) {
		printf("\n\n Errore: Password errata.");
	} else {
		printf("\n\n Errore: Utente inesistente.");
	}

	return false;
}

bool driverLogin(User_t *User) {
	FILE *IsleDriverData = NULL;
	User_t tmpUser;	
	
	IsleDriverData = fopen("./data/DriverLoginData.isle", "r");

	if(!IsleDriverData) {
		fclose(IsleDriverData);	
		IsleDriverData = fopen("./data/DriverLoginData.isle", "w");
		fclose(IsleDriverData);
		IsleDriverData = fopen("./data/DriverLoginData.isle", "r");
	}
	
	if(!IsleDriverData) error(1000);	
	
	int i = 0;

	for(i = 0; i < strlen(User->CF); i++) {
		User->CF[i] = toupper(User->CF[i]);
	}
	
	while(!feof(IsleDriverData)) {
		fscanf(IsleDriverData, "%s %s", tmpUser.CF, tmpUser.Password);
		if(strcmp(tmpUser.CF, User->CF) == 0) {
			if(strcmp(tmpUser.Password, User->Password) == 0) {
				fclose(IsleDriverData);
				return true;
			}
			break;
		}
	}
	
	fclose(IsleDriverData);
	
	if(strcmp(tmpUser.CF, User->CF) == 0 && strcmp(tmpUser.Password, User->Password) != 0) {
		printf("\n\n Errore: Password errata.");
	} else {
		printf("\n\n Errore: Utente inesistente.");
	}
	
	return false;
}

bool customerRegistration(User_t *User) {
    int i = 0;
    
	if(strlen(User->Password) == 0) {
		printf("\n\n Errore: Password non valida.");
		return false;
	}
	
	for(i = 0; i < strlen(User->CF); i++) {
		User->CF[i] = toupper(User->CF[i]);
	}
	
	if(!checkCFValidity(User->CF)) {
		printf("\n\n Errore: CF non valido.");
		return false;
	}

	FILE *IsleCustomerData = fopen("./data/CustomerLoginData.isle", "r+");

	if(!IsleCustomerData) {
		fclose(IsleCustomerData);
		IsleCustomerData = fopen("./data/CustomerLoginData.isle", "w");
		fclose(IsleCustomerData);
		IsleCustomerData = fopen("./data/CustomerLoginData.isle", "r+");
	}

	if(!IsleCustomerData) error(1000);

	String tmpCF;
	String buff;

	while(!feof(IsleCustomerData)) {
		fscanf(IsleCustomerData, "%s %s", tmpCF, buff);
		if(strcmp(tmpCF, User->CF) == 0) {
			fclose(IsleCustomerData);
			printf("\n\n Errore: Utente gia' esistente.");
			return false;
		}
	}
	
	fclose(IsleCustomerData);
	
	IsleCustomerData = fopen("./data/CustomerLoginData.isle", "a");
	
	if(!IsleCustomerData) error(1000);
	
	if(fprintf(IsleCustomerData, "%s %s\n", User->CF, User->Password) >= 0) {
		fclose(IsleCustomerData);
		return true;
	} else {
		fclose(IsleCustomerData);
		return false;
	}

	fclose(IsleCustomerData);
	return false;
}

bool driverRegistration(User_t *User) {
	
    int i = 0;
    
	if(strlen(User->Password) == 0) {
		printf("\n\n Errore: Password non valida.");
		return false;
	}
	
	for(i = 0; i < strlen(User->CF); i++) {
		User->CF[i] = toupper(User->CF[i]);
	}
	
	if(!checkCFValidity(User->CF)) {
		printf("\n\n Errore: CF non valido.");
		return false;
	}

	FILE *IsleDriverData = fopen("./data/DriverLoginData.isle", "r+");

	if(!IsleDriverData) {
		fclose(IsleDriverData);
		IsleDriverData = fopen("./data/DriverLoginData.isle", "w");
		fclose(IsleDriverData);
		IsleDriverData = fopen("./data/DriverLoginData.isle", "r+");
	}

	if(!IsleDriverData) error(1000);

	String tmpCF;
	String buff;

	while(!feof(IsleDriverData)) {
		fscanf(IsleDriverData, "%s %s", tmpCF, buff);
		if(strcmp(tmpCF, User->CF) == 0) {
			fclose(IsleDriverData);
			printf("\n\n Errore: Utente gia' esistente.");
			return false;
		}
	}
	
	fclose(IsleDriverData);
	
	IsleDriverData = fopen("./data/DriverLoginData.isle", "a");
	
	if(!IsleDriverData) error(1000);
	
	if(fprintf(IsleDriverData, "%s %s\n", User->CF, User->Password) >= 0) {
		fclose(IsleDriverData);
		return true;
	} else {
		fclose(IsleDriverData);
		return false;
	}

	fclose(IsleDriverData);
	return false;
}

