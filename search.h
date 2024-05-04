#ifndef SEARCH
#define SEARCH

#include <string.h>

#include "types.h"

Guest binarySearch(Guest* guests, char* name, int low, int high);
Guest binarySearchByRoomId(Guest* guests, char roomId, int low, int high);

#endif