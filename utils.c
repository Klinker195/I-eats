#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "headers/utils.h"
#include "headers/cliui.h"

const int adminKey = 1000;

bool searchCF(FILE *fp, String CF) {
	
	String tmpCF;
	
	while(!feof(fp)) {
		fgets(tmpCF, 256, fp);
		sscanf(tmpCF, "%16s %*", tmpCF);
		if(strncmp(tmpCF, CF, 16) == 0) {
			return true;
		}
	}
	
	return false;
}

void error(int errorNumber) {
	
	switch(errorNumber) {
		case 1000:
			system("cls");
			printf(ANSI_COLOR_RED" [ERRORE NUMERO #%d]", errorNumber);
			printf(" Apertura file non riuscita.\n\n"ANSI_COLOR_RESET);
			system("pause");
			exit(errorNumber);
			break;
		case 1001:
			system("cls");
			printf(ANSI_COLOR_RED" [ERRORE NUMERO #%d]", errorNumber);
			printf(" Impossibile allocare memoria.\n\n"ANSI_COLOR_RESET);
			system("pause");
			exit(errorNumber);
			break;
		default:
		
			break;
	}
	
}

int validateAtoi(String intArg) {
	
	int i = 0;
	
	for(i = 0; i < strlen(intArg); i++) {
		if(!isdigit(intArg[i])) {
			return -1;
		}
	}
	
	return atoi(intArg);
}

bool checkCFValidity(String CF) {
	
	if(strlen(CF) != 16) return false;
	
	int i = 0;
	bool check = false;
	
	for(i = 0; i < 6; i++) {
		if(CF[i] >= 65 && CF[i] <= 90) {
			check = true;
		}
	}
	
	if(!check) return false;
	
	check = false;
	
	for(i = 6; i < 8; i++) {
		if(CF[i] >= 48 && CF[i] <= 57) {
			check = true;
		}
	}
	
	if(!check) return false;
	
	check = false;
	
	if(!(CF[8] >= 65 && CF[i] <= 90)) return false;
	
	for(i = 9; i < 11; i++) {
		if(CF[i] >= 48 && CF[i] <= 57) {
			check = true;
		}
	}
	
	if(!check) return false;
	
	check = false;
	
	if(!(CF[11] >= 65 && CF[i] <= 90)) return false;
	
	for(i = 12; i < 15; i++) {
		if(CF[i] >= 48 && CF[i] <= 57) {
			check = true;
		}
	}
	
	if(!check) return false;
	
	if(!(CF[15] >= 65 && CF[i] <= 90)) return false;
	
	return check;
}

unsigned int fetchID() {

	FILE *IsleIslandID;

	IsleIslandID = fopen("./data/IslandIDs.isle", "r");

	if(!IsleIslandID) {
		fclose(IsleIslandID);
		IsleIslandID = fopen("./data/IslandIDs.isle", "w");
		fprintf(IsleIslandID, "1000\n");
		fclose(IsleIslandID);
		IsleIslandID = fopen("./data/IslandIDs.isle", "r");
	}
	
	if(!IsleIslandID) error(1000);
	
	unsigned int newID = 0;
	
	fscanf(IsleIslandID, "%d", &newID);
	
	fclose(IsleIslandID);
	IsleIslandID = fopen("./data/IslandIDs.isle", "w");
	
	fprintf(IsleIslandID, "%d\n", newID + 1);
	
	fclose(IsleIslandID);
	
	return newID;
}

