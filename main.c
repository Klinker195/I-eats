#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "headers/cliui.h"
#include "headers/utils.h"
#include "headers/datastructures.h"

int main(void) {

	User_t ConnectedUser;
	
	srand(time(NULL));
	
	fullscreen();
	
	int Modality = isleStart(&ConnectedUser);
	
	if(Modality == 0) {
		isleDriver(&ConnectedUser);
	} else if(Modality == 1) {
		isleCustomer(&ConnectedUser);
	} else {
		isleDebug();
	}
	
	return 0;
}
