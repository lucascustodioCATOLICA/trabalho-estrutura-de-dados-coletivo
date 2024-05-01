#ifndef FILE_SYSTEM
#define FILE_SYSTEM

#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "utils.h"

int readFile(Guest*);
void writeFile(Guest*, int);

#endif