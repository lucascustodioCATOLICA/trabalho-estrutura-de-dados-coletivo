#ifndef OPERATIONS
#define OPERATIONS

#include <ctype.h>

#include "types.h"
#include "sort.h"
#include "filesystem.h"
#include "utils.h"
#include "search.h"

int insertArtist(Artist*, int);
int removeArtist(Artist*, int);
void editArtist(Artist*, int);
void binarySearchByName(Artist*, int);
void SequencialSearchByAlbum(Artist*, int);

#endif