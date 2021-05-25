#ifndef CLIUI_H
#define CLIUI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_BRIGHTRED     "\x1b[91m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BRIGHTYELLOW "\x1b[93m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define STARTUPCHOICELIST_SIZE 4
#define LOGINREGISTRATIONCHOICELIST_SIZE 2
#define DRIVERCHOICELIST_SIZE 3
#define CUSTOMERCHOICELIST_SIZE 2
#define CONFIRMORDERCHOICELIST_SIZE 3

typedef struct {
	const String Text;
	bool Selected;
} Choice_t;

extern Choice_t StartupChoiceList[STARTUPCHOICELIST_SIZE];
extern Choice_t LoginRegistrationChoiceList[LOGINREGISTRATIONCHOICELIST_SIZE];
extern Choice_t DriverChoiceList[DRIVERCHOICELIST_SIZE];
extern Choice_t CustomerChoiceList[CUSTOMERCHOICELIST_SIZE];
extern Choice_t ConfirmOrderChoiceList[CONFIRMORDERCHOICELIST_SIZE];

void printMainMenu(Choice_t ChoiceList[], int TotalChoices);

void printOrderConfirmationChoice(Choice_t ChoiceList[], int TotalChoices);

void printLoginChoice(Choice_t ChoiceList[], int TotalChoices);

void printRegistrationChoice(Choice_t ChoiceList[], int TotalChoices);

void printDriverChoice(Choice_t ChoiceList[], int TotalChoices);

void printCustomerChoice(Choice_t ChoiceList[], int TotalChoices);

void printVerticalOptions(Choice_t ChoiceList[], int TotalChoices);

int getVerticalInput(Choice_t ChoiceList[], int TotalChoices, void (*printOptions)(Choice_t[], int));

#endif
