#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "headers/account.h"

bool customerLogin(User_t *User) {
	FILE *IsleCustomerData = NULL;
	User_t tmpUser;	
	
	IsleCustomerData = fopen("./data/IslandIDs.isle", "r");

	if(!IsleCustomerData) {
		fclose(IsleCustomerData);	
		IsleCustomerData = fopen("./data/IslandIDs.isle", "w");
		fclose(IsleCustomerData);
		IsleCustomerData = fopen("./data/IslandIDs.isle", "r");
	}
	
	if(!IsleCustomerData) error(1000);	
	
	while(fscanf(IsleCustomerData,"%s %s", tmpUser.CF, tmpUser.Password) == 2) {
		if(strncmp(User->CF, tmpUser.CF, 16) == 0 && strcmp(User->Password, tmpUser.Password) == 0) {
			fclose(IsleCustomerData);
			return true;
		}
	}
	
	fclose(IsleCustomerData);
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
	
	while(fscanf(IsleDriverData,"%s %s", tmpUser.CF, tmpUser.Password) == 2) {
		if(strncmp(User->CF, tmpUser.CF, 16) == 0 && strcmp(User->Password, tmpUser.Password) == 0) {
			fclose(IsleDriverData);
			return true;
		}
	}
	
	fclose(IsleDriverData);
	return false;
}

void customerRegistration(User_t *User) {
    FILE *IsleCustomerData = NULL;
	
	IsleCustomerData = fopen("./data/IslandIDs.isle", "a");

	if(!IsleCustomerData) error(1000);

	fprintf(IsleCustomerData, "%s %s\n", User->CF, User->Password);
	
	fclose(IsleCustomerData);	
}

void driverRegistration(User_t *User) {
	FILE *IsleDriverData = NULL;
	
	IsleDriverData = fopen("./data/DriverLoginData.isle", "a");

	if(!IsleDriverData) error(1000);

	fprintf(IsleDriverData, "%s %s\n", User->CF, User->Password);
	
	fclose(IsleDriverData);	
}

