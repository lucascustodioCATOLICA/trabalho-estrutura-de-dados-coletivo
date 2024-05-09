#include "search.h"

Guest binarySearch(Guest* guest, char* name, int low, int high)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (strcmp(guest[mid].name, name) == 0)
            return guest[mid];
        if (strcmp(guest[mid].name, name) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    Guest guestNotFound;
    strcpy(guestNotFound.name, "NULL");
    return guestNotFound;
}

Guest* binarySearchPtr(Guest* guest, char* name, int low, int high)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (strcmp(guest[mid].name, name) == 0)
            return &guest[mid];
        if (strcmp(guest[mid].name, name) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    Guest *guestNotFound = (Guest*) malloc(sizeof(Guest));
    strcpy(guestNotFound->name, "NULL");
    return guestNotFound;
}

Guest searchByRoomId(Guest* guest, char roomId, int size)
{
    for (int i = 0; i<size; i++) {
        if(guest[i].roomId == roomId) {
            return guest[i];
        }
    }

    Guest guestNotFound;
    strcpy(guestNotFound.name, "NULL");
    return guestNotFound;
}