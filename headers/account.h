#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "utils.h"

bool customerLogin(User_t *User);

bool driverLogin(User_t *User);

void customerRegistration(User_t *User);

void driverRegistration(User_t *User);

#endif
