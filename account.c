#include "headers/account.h"


int clientLogin(User_t User)
{
	
	
}

int driverLogin(User_t User)
{
int i=0;
FILE* fp = NULL;	
User_t UserCheck;	
	
fp = fopen("Driverdata.txt", "r");	
	
while(fscanf(fp,"%s %s", UserCheck.CF, UserCheck.Password)==2)
{
	system("pause");
	if(strcmp(User.CF, UserCheck.CF)==0 && strcmp(User.Password, UserCheck.Password)==0)
	 i=1;
	 system("pause");
} 

return i;	
}

void clientRegistration(User_t User)
{
	
	
	
}

void driverRegistration(User_t User)
{
FILE* fp = NULL;	
	
fp = fopen("Driverdata.txt", "a");

fprintf(fp, "%s %s", User.CF, User.Password);
	
fclose(fp);	
	
}

