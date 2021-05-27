#ifndef ISLE_H
#define ISLE_H

#include "utils.h"
#include "datastructures.h"

int isleStart(User_t *ConnectedUser);

void isleDriver(User_t *ConnectedUser);

void isleDriverChangeVehicleModel(User_t *ConnectedUser);

void isleCustomer(User_t *ConnectedUser);

bool isleCustomerPlaceOrder(User_t *ConnectedUser, Node_t *ResourcesList, Node_t *VertexList);

bool addResource(Resource_t *Resource, Node_t *ResourceList);

void swapUserVehicle(User_t *ConnectedUser, String Model);

bool checkOrderUniqueness(String CF);

#endif
