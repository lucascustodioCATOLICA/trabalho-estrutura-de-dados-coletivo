#ifndef SEARCH
#define SEARCH

#include <string.h>
#include <stdlib.h>

#include "types.h"

Guest binarySearch(Guest* guests, char* name, int low, int high);
Guest* binarySearchPtr(Guest* guests, char* name, int low, int high);
Guest searchByRoomId(Guest* guests, char roomId, int size);

#endif