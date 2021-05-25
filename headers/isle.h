#ifndef ISLE_H
#define ISLE_H

#include "utils.h"
#include "datastructures.h"

int isleStart(User_t *ConnectedUser);

void isleDriver(User_t *ConnectedUser);

void isleCustomer(User_t *ConnectedUser);

bool isleCustomerPlaceOrder(User_t *ConnectedUser, Node_t *ResourcesList);

bool addResource(Resource_t *Resource, Node_t *ResourceList);

#endif
