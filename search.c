#include "search.h"

Artist binarySearch(Artist* artists, char* name, int low, int high)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (strcmp(artists[mid].name, name) == 0)
            return artists[mid];
        if (strcmp(artists[mid].name, name) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    Artist artistNotFound;
    strcpy(artistNotFound.name, "NULL");
    return artistNotFound;
}