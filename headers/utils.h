#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

#define STRING_LENGTH 256

typedef char String[STRING_LENGTH];

typedef struct {
	String CF;
	String Password;
} User_t;

bool searchCF(FILE *fp, String CF);

void error(int errorNumber);

int validateAtoi(String intArg);

bool checkCFValidity(String CF);

#endif
