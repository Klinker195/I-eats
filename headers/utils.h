#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdio.h>

#define STRING_LENGTH 256

typedef char String[STRING_LENGTH];

extern const int adminKey;

typedef struct {
	String CF;
	String Password;
} User_t;

typedef struct {
	unsigned int x;
	unsigned int y;
} IdPair_t;

typedef struct {
	String Name;
	double SpecificWeight;
} Resource_t;

typedef struct {
	String Name;
	Resource_t Resource;
} IsleInfo_t;

bool searchCF(FILE *fp, String CF);

void error(int errorNumber);

int validateAtoi(String intArg);

bool checkCFValidity(String CF);

unsigned int fetchID();

#endif
