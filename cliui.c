#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers/cliui.h"

Choice_t StartupChoiceList[STARTUPCHOICELIST_SIZE] = { {"Effettuare il login", false}, {"Effettuare una registrazione", false}, {"Debug", false}, {"Esci dal software", false} };
Choice_t LoginRegistrationChoiceList[LOGINREGISTRATIONCHOICELIST_SIZE] = { {"Driver", false}, {"Cliente", false} };
Choice_t DriverChoiceList[DRIVERCHOICELIST_SIZE] = { {"Seleziona ordine", false}, {"Cambia informazioni veicolo", false}, {"Esci", false}};
Choice_t CustomerChoiceList[CUSTOMERCHOICELIST_SIZE] = { {"Effettua ordine", false}, {"Esci", false} };


void printMainMenu(Choice_t ChoiceList[], int TotalChoices) {
	
	system("cls");
	
	/*
	ASCII Art Style = Georgia11
	Effettuata sul sito: https://patorjk.com/software/taag/
	*/
	
	printf(ANSI_COLOR_BRIGHTRED " +----------------------------------------------------------------+\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"                                                                "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"         ____       __________                                  "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"         `MM'       `MMMMMMMMM                                  "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"          MM         MM      \\           /                      "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"          MM         MM           ___   /M       ____           "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"          MM         MM    ,    6MMMMb /MMMMM   6MMMMb\\         "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"          MM         MMMMMMM   8M'  `Mb MM     MM'    `         "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"          MM         MM    `       ,oMM MM     YM.              "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"          MM MMMMMMM MM        ,6MM9'MM MM      YMMMMb          "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"          MM         MM        MM'   MM MM          `Mb         "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"          MM         MM      / MM.  ,MM YM.  , L    ,MM         "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"         _MM_       _MMMMMMMMM `YMMM9'Yb.YMMM9 MYMMMM9          "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"                                                                "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"   Utilizzare le frecce direzionali per muoversi nel software.  "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"                                                                "ANSI_COLOR_BRIGHTRED "|\n");
	printf(ANSI_COLOR_BRIGHTRED " |----------------------------------------------------------------|\n");
	
	int i = 0;
	
	for(i = 0; i < TotalChoices; i++) {
		
		if(ChoiceList[i].Selected) {
			printf(" |                                                                |\n");
			printf(" |             +-----------------------------------+              |\n");
			printf(" |             |"ANSI_COLOR_BRIGHTYELLOW" > | %29s "ANSI_COLOR_BRIGHTRED"|              |\n", ChoiceList[i].Text);
			printf(" |             +-----------------------------------+              |\n");
			printf(" |                                                                |\n");
		} else {
			printf(" |                                                                |\n");
			printf(" |             +-----------------------------------+              |\n");
			printf(" |             |   | %29s |              |\n", ChoiceList[i].Text);
			printf(" |             +-----------------------------------+              |\n");
			printf(" |                                                                |\n");
		}
		
	}
	
	printf(" +----------------------------------------------------------------+\n"ANSI_COLOR_RESET);
	
	
}






void printLoginChoice(Choice_t ChoiceList[], int TotalChoices) {
	
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
	
	int i = 0;
	
	for(i = 0; i < TotalChoices; i++) {
		
		if(ChoiceList[i].Selected) {
			printf(" |--------------------------------------|\n");
			printf(" |                                      |\n");
			printf(" |     +-------------------------+      |\n");
			printf(" |     |"ANSI_COLOR_BRIGHTYELLOW" > | %19s "ANSI_COLOR_BRIGHTRED"|      |\n", ChoiceList[i].Text);
			printf(" |     +-------------------------+      |\n");
			printf(" |                                      |\n");
		} else {
			printf(" |--------------------------------------|\n");
			printf(" |                                      |\n");
			printf(" |     +-------------------------+      |\n");
			printf(" |     |   | %19s |      |\n", ChoiceList[i].Text);
			printf(" |     +-------------------------+      |\n");
			printf(" |                                      |\n");
		}
		
	}
	
	printf(" +--------------------------------------+\n"ANSI_COLOR_RESET);
	
	
}

void printRegistrationChoice(Choice_t ChoiceList[], int TotalChoices) {
	
	system("cls");
	
	/*
	ASCII Art Style = Doom
	Effettuata sul sito: https://patorjk.com/software/taag/
	*/
	
	printf(ANSI_COLOR_BRIGHTRED " +----------------------------------------------------+\n");
	printf(" |"ANSI_COLOR_BRIGHTYELLOW"   ______               _       _                   "ANSI_COLOR_BRIGHTRED"|\n");
	printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | ___ \\             (_)     | |                  "ANSI_COLOR_BRIGHTRED"|\n");
	printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |_/ /  ___   __ _  _  ___ | |_   ___  _ __     "ANSI_COLOR_BRIGHTRED"|\n");
	printf(" |"ANSI_COLOR_BRIGHTYELLOW"   |    /  / _ \\ / _` || |/ __|| __| / _ \\| '__|    "ANSI_COLOR_BRIGHTRED"|\n");
	printf(" |"ANSI_COLOR_BRIGHTYELLOW"   | |\\ \\ |  __/| (_| || |\\__ \\| |_ |  __/| |       "ANSI_COLOR_BRIGHTRED"|\n");
	printf(" |"ANSI_COLOR_BRIGHTYELLOW"   \\_| \\_| \\___| \\__, ||_||___/ \\__| \\___||_|       "ANSI_COLOR_BRIGHTRED"|\n");
	printf(" |"ANSI_COLOR_BRIGHTYELLOW"                  __/ |                             "ANSI_COLOR_BRIGHTRED"|\n");
	printf(" |"ANSI_COLOR_BRIGHTYELLOW"                 |___/                              "ANSI_COLOR_BRIGHTRED"|\n");
	
	int i = 0;
	
	for(i = 0; i < TotalChoices; i++) {
		
		if(ChoiceList[i].Selected) {
			printf(" |----------------------------------------------------|\n");
			printf(" |                                                    |\n");
			printf(" |            +-------------------------+             |\n");
			printf(" |            |"ANSI_COLOR_BRIGHTYELLOW" > | %19s "ANSI_COLOR_BRIGHTRED"|             |\n", ChoiceList[i].Text);
			printf(" |            +-------------------------+             |\n");
			printf(" |                                                    |\n");
		} else {
			printf(" |----------------------------------------------------|\n");
			printf(" |                                                    |\n");
			printf(" |            +-------------------------+             |\n");
			printf(" |            |   | %19s |             |\n", ChoiceList[i].Text);
			printf(" |            +-------------------------+             |\n");
			printf(" |                                                    |\n");
		}
		
	}
	
	printf(" +----------------------------------------------------+\n"ANSI_COLOR_RESET);
	
	
}

void printDriverChoice(Choice_t ChoiceList[], int TotalChoices) {
	
	system("cls");
	
	/*
	ASCII Art Style = Doom
	Effettuata sul sito: https://patorjk.com/software/taag/
	*/
	
	printf(ANSI_COLOR_BRIGHTRED " +-------------------------------------------------------------------+\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"      ______      _                 ______                _        "ANSI_COLOR_BRIGHTRED"|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"      |  _  \\    (_)                | ___ \\              | |       "ANSI_COLOR_BRIGHTRED"|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"      | | | |_ __ ___   _____ _ __  | |_/ /_ _ _ __   ___| |       "ANSI_COLOR_BRIGHTRED"|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"      | | | | '__| \\ \\ / / _ \\ '__| |  __/ _` | '_ \\ / _ \\ |       "ANSI_COLOR_BRIGHTRED"|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"      | |/ /| |  | |\\ V /  __/ |    | | | (_| | | | |  __/ |       "ANSI_COLOR_BRIGHTRED"|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"      |___/ |_|  |_| \\_/ \\___|_|    \\_|  \\__,_|_| |_|\\___|_|       "ANSI_COLOR_BRIGHTRED"|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"                                                                   "ANSI_COLOR_BRIGHTRED"|\n");
	
	int i = 0;
	
	for(i = 0; i < TotalChoices; i++) {
		
		if(ChoiceList[i].Selected) {
			printf(" |-------------------------------------------------------------------|\n");
			printf(" |                                                                   |\n");
			printf(" |                +---------------------------------+                |\n");
			printf(" |                |"ANSI_COLOR_BRIGHTYELLOW" > | %27s "ANSI_COLOR_BRIGHTRED"|                |\n", ChoiceList[i].Text);
			printf(" |                +---------------------------------+                |\n");
			printf(" |                                                                   |\n");
		} else {
			printf(" |-------------------------------------------------------------------|\n");
			printf(" |                                                                   |\n");
			printf(" |                +---------------------------------+                |\n");
			printf(" |                |   | %27s |                |\n", ChoiceList[i].Text);
			printf(" |                +---------------------------------+                |\n");
			printf(" |                                                                   |\n");
		}
		
	}
	
	printf(" +-------------------------------------------------------------------+\n"ANSI_COLOR_BRIGHTYELLOW);
	
	
}

void printCustomerChoice(Choice_t ChoiceList[], int TotalChoices) {
	
	system("cls");
	
	/*
	ASCII Art Style = Doom
	Effettuata sul sito: https://patorjk.com/software/taag/
	*/
	
	printf(ANSI_COLOR_BRIGHTRED " +-----------------------------------------------------------------------------------------+\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"          _____           _                             ______                _          "ANSI_COLOR_BRIGHTRED"|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"         /  __ \\         | |                            | ___ \\              | |         "ANSI_COLOR_BRIGHTRED"|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"         | /  \\/_   _ ___| |_ ___  _ __ ___   ___ _ __  | |_/ /_ _ _ __   ___| |         "ANSI_COLOR_BRIGHTRED"|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"         | |   | | | / __| __/ _ \\| '_ ` _ \\ / _ \\ '__| |  __/ _` | '_ \\ / _ \\ |         "ANSI_COLOR_BRIGHTRED"|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"         | \\__/\\ |_| \\__ \\ || (_) | | | | | |  __/ |    | | | (_| | | | |  __/ |         "ANSI_COLOR_BRIGHTRED"|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"          \\____/\\__,_|___/\\__\\___/|_| |_| |_|\\___|_|    \\_|  \\__,_|_| |_|\\___|_|         "ANSI_COLOR_BRIGHTRED"|\n");
	printf(ANSI_COLOR_BRIGHTRED " |"ANSI_COLOR_BRIGHTYELLOW"                                                                                         "ANSI_COLOR_BRIGHTRED"|\n");
	
	int i = 0;
	
	for(i = 0; i < TotalChoices; i++) {
		
		if(ChoiceList[i].Selected) {
			printf(" |-----------------------------------------------------------------------------------------|\n");
			printf(" |                                                                                         |\n");
			printf(" |                            +--------------------------------+                           |\n");
			printf(" |                            |"ANSI_COLOR_BRIGHTYELLOW" > | %26s "ANSI_COLOR_BRIGHTRED"|                           |\n", ChoiceList[i].Text);
			printf(" |                            +--------------------------------+                           |\n");
			printf(" |                                                                                         |\n");
		} else {
			printf(" |-----------------------------------------------------------------------------------------|\n");
			printf(" |                                                                                         |\n");
			printf(" |                            +--------------------------------+                           |\n");
			printf(" |                            |   | %26s |                           |\n", ChoiceList[i].Text);
			printf(" |                            +--------------------------------+                           |\n");
			printf(" |                                                                                         |\n");
		}
		
	}
	
	printf(" +-----------------------------------------------------------------------------------------+\n"ANSI_COLOR_BRIGHTYELLOW);
	
	
}

void printVerticalOptions(Choice_t ChoiceList[], int TotalChoices) {
	
	system("cls");
	
	printf(" Select the options using arrows:\n\n");
	
	int i = 0;
	
	for(i = 0; i < TotalChoices; i++) {
		
		if(ChoiceList[i].Selected) {
			printf(" +--------------------------------------+\n");
			printf(" | > | %32s |\n", ChoiceList[i].Text);
			printf(" +--------------------------------------+\n");
		} else {
			printf(" +--------------------------------------+\n");
			printf(" |   | %32s |\n", ChoiceList[i].Text);
			printf(" +--------------------------------------+\n");
		}
		
	}
	
}

int getVerticalInput(Choice_t ChoiceList[], int TotalChoices, void (*printOptions)(Choice_t[], int)) {
	
	char key_code;
	
	int option = 0;
	int i = 0;
	
	ChoiceList[0].Selected = true;
	
	printOptions(ChoiceList, TotalChoices);
	
	while(1) {
		
		if(_kbhit()) {
			
			key_code = _getch();
			
			int tmp;
			
			if(key_code == 72) {
				tmp = option;
				tmp--;
				if(tmp >= 0) {
					ChoiceList[option].Selected = false;
					option--;
					ChoiceList[option].Selected = true;
					printOptions(ChoiceList, TotalChoices);
				}
			} else if (key_code == 80){
				tmp = option;
				tmp++;
				if(tmp < TotalChoices) {
					ChoiceList[option].Selected = false;
					option++;
					ChoiceList[option].Selected = true;
					printOptions(ChoiceList, TotalChoices);
				}
			} else if(key_code == 13) {
				
				for(i = 0; i < TotalChoices; i++) {
					ChoiceList[i].Selected = false;
				}
				
				return option;
				
			}
		}
		
	}
	
	
}
