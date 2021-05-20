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

						printf(ANSI_COLOR_CYAN" +--------------------------------------+\n");
						printf(" |    _                    _            |\n");
						printf(" |   | |                  (_)           |\n");
						printf(" |   | |      ___    __ _  _  _ __      |\n");
						printf(" |   | |     / _ \\  / _` || || '_ \\     |\n");
						printf(" |   | |____| (_) || (_| || || | | |    |\n");
						printf(" |   \\_____/ \\___/  \\__, ||_||_| |_|    |\n");
						printf(" |                   __/ |              |\n");
						printf(" |                  |___/               |\n");
						printf(" +--------------------------------------+\n"ANSI_COLOR_RESET);

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
						
						// TODO: Do login #1
						/*
						if(loginStandardUser(&User))  {
							loginDone = true;
							*CurrentUser = User;
							return 0;
						} else {
							strcpy(User.CF, "");
							strcpy(User.Password, "");

							printf("\n\n");
							printf(" Login fallito, reindirizzamento al menu' principale...");
							sleep(2);
						}
						*/
						break;
					case 1:
						system("cls");

						/*
						ASCII Art Style = Doom
						Effettuata sul sito: https://patorjk.com/software/taag/
						*/

						printf(ANSI_COLOR_CYAN" +--------------------------------------+\n");
						printf(" |    _                    _            |\n");
						printf(" |   | |                  (_)           |\n");
						printf(" |   | |      ___    __ _  _  _ __      |\n");
						printf(" |   | |     / _ \\  / _` || || '_ \\     |\n");
						printf(" |   | |____| (_) || (_| || || | | |    |\n");
						printf(" |   \\_____/ \\___/  \\__, ||_||_| |_|    |\n");
						printf(" |                   __/ |              |\n");
						printf(" |                  |___/               |\n");
						printf(" +--------------------------------------+\n"ANSI_COLOR_RESET);

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
						
						// TODO: Do login #2
						/*
						if(loginStandardUser(&User))  {
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
						*/
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

						printf(ANSI_COLOR_CYAN" +----------------------------------------------------+\n");
						printf(" |   ______               _       _                   |\n");
						printf(" |   | ___ \\             (_)     | |                  |\n");
						printf(" |   | |_/ /  ___   __ _  _  ___ | |_   ___  _ __     |\n");
						printf(" |   |    /  / _ \\ / _` || |/ __|| __| / _ \\| '__|    |\n");
						printf(" |   | |\\ \\ |  __/| (_| || |\\__ \\| |_ |  __/| |       |\n");
						printf(" |   \\_| \\_| \\___| \\__, ||_||___/ \\__| \\___||_|       |\n");
						printf(" |                  __/ |                             |\n");
						printf(" |                 |___/                              |\n");
						printf(" +----------------------------------------------------+\n"ANSI_COLOR_RESET);

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
						
						// TODO: Do register #1
						/*
						if(strcmp(verifyPassword, User.Password) == 0 && registerStandardUser(&User))  {
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
						*/
						break;
					case 1:

						system("cls");

						/*
						ASCII Art Style = Doom
						Effettuata sul sito: https://patorjk.com/software/taag/
						*/

						printf(ANSI_COLOR_CYAN" +----------------------------------------------------+\n");
						printf(" |   ______               _       _                   |\n");
						printf(" |   | ___ \\             (_)     | |                  |\n");
						printf(" |   | |_/ /  ___   __ _  _  ___ | |_   ___  _ __     |\n");
						printf(" |   |    /  / _ \\ / _` || |/ __|| __| / _ \\| '__|    |\n");
						printf(" |   | |\\ \\ |  __/| (_| || |\\__ \\| |_ |  __/| |       |\n");
						printf(" |   \\_| \\_| \\___| \\__, ||_||___/ \\__| \\___||_|       |\n");
						printf(" |                  __/ |                             |\n");
						printf(" |                 |___/                              |\n");
						printf(" +----------------------------------------------------+\n"ANSI_COLOR_RESET);

						int tmpLabKey;

						printf("\n\n");
						printf(" Inserisci la chiave di sicurezza: ");
						gets(intArg);

						tmpLabKey = validateAtoi(intArg);

						printf("\n");

						if(tmpLabKey != labKey) {
							printf("\n\n Errore: La chiave di sicurezza non e' valida.");

							strcpy(User.CF, "");
							strcpy(User.Password, "");
							strcpy(verifyPassword, "");

							printf("\n\n");
							printf(" Registrazione fallita, reindirizzamento al menu' principale...");
							sleep(3);
							break;
						}

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
						
						// TODO: Do register #2
						/*
						if(strcmp(verifyPassword, User.Password) == 0 && registerLabUser(&User))  {
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
						*/
						break;
				}
				break;
			case 2:
				exit(0);
				break;
		}

	} while(!loginDone);

	return -1;
}