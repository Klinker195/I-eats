#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "headers/account.h"

bool customerLogin(User_t *User) {
	// TODO: Customer Login
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
	
	while(fscanf(fp,"%s %s", tmpUser.CF, tmpUser.Password) == 2) {
		if(strncmp(User->CF, tmpUser.CF, 16) == 0 && strcmp(User->Password, tmpUser.Password) == 0) {
			fclose(IsleDriverData);
			return true;
		}
	}
	
	fclose(IsleDriverData);
	return false;
}

void customerRegistration(User_t *User) {
	// TODO: Customer Registration
}

void driverRegistration(User_t *User) {
	FILE *IsleDriverData = NULL;
	
	IsleDriverData = fopen("./data/DriverLoginData.isle", "a");

	if(!IsleDriverData) error(1000);

	fprintf(IsleDriverData, "%s %s\n", User->CF, User->Password);
	
	fclose(IsleDriverData);	
}

