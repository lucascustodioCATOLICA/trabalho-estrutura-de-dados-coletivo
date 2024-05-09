#ifndef OPERATIONS
#define OPERATIONS

#include <ctype.h>
#include <windows.h>
#include <unistd.h>

#include "types.h"
#include "sort.h"
#include "filesystem.h"
#include "utils.h"
#include "search.h"
#include "commands.h"

int insertGuests(Guest*, int);
void listGuests(Guest*, int);
void getGuestByName(Guest*, int);
void editGuest(Guest*, int);
int removeGuest(Guest*, int);
void countEmptyRooms(Guest*, int);
void saveFile(Guest*, int);

#endif