#ifndef OPERATIONS
#define OPERATIONS

#include <ctype.h>

#include "types.h"
#include "sort.h"
#include "filesystem.h"
#include "utils.h"
#include "search.h"

int insertGuests(Guest*, int);
void listGuests(Guest*, int);
void getGuestByName(Guest*, int);
void editGuest(Guest*, int);
int removeGuest(Guest*, int);
void countEmptyRooms(Guest*, int);
void saveFile(Guest*, int);

#endif