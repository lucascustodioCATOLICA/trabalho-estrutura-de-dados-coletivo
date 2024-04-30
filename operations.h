#ifndef OPERATIONS
#define OPERATIONS

#include <ctype.h>

#include "types.h"
#include "sort.h"
#include "filesystem.h"
#include "utils.h"
#include "search.h"

int insertGuests(Artist*, int);
void listGuests(Artist*, int);
void getGuestByName(Artist*, int);
void editGuest(Artist*, int);
void setEmptyRoom(Artist*, int);
void countEmptyRooms(Artist*, int);
void saveFile(Artist*, int);

#endif