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

Guest binarySearchByRoomId(Guest* guest, char roomId, int low, int high)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (guest[mid].roomId == roomId)
            return guest[mid];
        if (guest[mid].roomId < roomId)
            low = mid + 1;
        else
            high = mid - 1;
    }

    Guest guestNotFound;
    strcpy(guestNotFound.name, "NULL");
    return guestNotFound;
}