#ifndef DEBUG_H
#define DEBUG_H

#include <stdbool.h>

#include "utils.h"
#include "datastructures.h"

bool addResource(Resource_t *Resource);

void endInsResourcesFromFile(Node_t **Head);

bool _deleteResourceAtPosition(Node_t **Head, int Pos, int CurrentPos);

bool deleteResourceAtPosition(Node_t **Head, int Pos);

void writeListIntoResourcesFile(Node_t **List, FILE *IsleResourceData);

int printResourcesList(Node_t **Head);

#endif
