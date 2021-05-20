#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers/cliui.h"

Choice_t StartupChoiceList[STARTUPCHOICELIST_SIZE] = { {"Effettuare il login", false}, {"Effettuare una registrazione", false}, {"Esci dal software", false} };

void printMainMenu(Choice_t ChoiceList[], int TotalChoices) {
	
	system("cls");
	
	/*
	ASCII Art Style = Georgia11
	Effettuata sul sito: https://patorjk.com/software/taag/
	*/
	
	String DateString = "";
	
	printf(ANSI_COLOR_CYAN " +----------------------------------------------------------------+\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET"                                                                "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET" ____       __________                                           "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET" `MM'       `MMMMMMMMM                                        "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET"  MM         MM      \           /                 "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET"  MM         MM           ___   /M       ____          "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET"  MM         MM    ,    6MMMMb /MMMMM   6MMMMb\        "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET"  MM         MMMMMMM   8M'  `Mb MM     MM'    `      "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET"  MM         MM    `       ,oMM MM     YM.           "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET"  MM MMMMMMM MM        ,6MM9'MM MM      YMMMMb         "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET"  MM         MM        MM'   MM MM          `Mb              "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET"  MM         MM      / MM.  ,MM YM.  , L    ,MM           "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET" _MM_       _MMMMMMMMM `YMMM9'Yb.YMMM9 MYMMMM9                "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET"                                                                "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET"   Utilizzare le frecce direzionali per muoversi nel software.  "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |"ANSI_COLOR_RESET"                                                                "ANSI_COLOR_CYAN "|\n");
	printf(ANSI_COLOR_CYAN " |----------------------------------------------------------------|\n");
	
	int i = 0;
	
	for(i = 0; i < TotalChoices; i++) {
		
		if(ChoiceList[i].Selected) {
			printf(" |                                                                |\n");
			printf(" |             +-----------------------------------+              |\n");
			printf(" |             |"ANSI_COLOR_RESET" > | %29s "ANSI_COLOR_CYAN"|              |\n", ChoiceList[i].Text);
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
