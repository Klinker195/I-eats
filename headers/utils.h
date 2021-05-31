#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdio.h>
#include <windows.h>

#define STRING_LENGTH 256

typedef char String[STRING_LENGTH];

typedef struct {
	unsigned int x;
	unsigned int y;
} IdPair_t;

typedef struct {
	String Model;
	double Weight;
} Vehicle_t;

typedef struct {
	String Name;
	double SpecificWeight;
	unsigned int Quantity;
} Resource_t;

#include "datastructures.h"

extern const int adminKey;

typedef struct {
	String CF;
	String Password;
	Vehicle_t Vehicle;
} User_t;

bool searchCF(FILE *fp, String CF);

void error(int errorNumber);

int validateAtoi(String intArg);

bool checkCFValidity(String CF);

unsigned int fetchID();

int findMin(int FirstValue, int SecondValue);

#endif
