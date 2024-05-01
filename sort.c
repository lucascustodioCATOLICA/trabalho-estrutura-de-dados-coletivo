#include "sort.h"

void sort(Guest* guests, int size)
{
    Guest tmp;
    for (int j = 0; j < size-1; j++) {
        for (int i = 0; i < size-1; i++) {
            if(strcmp(guests[i].name, guests[i + 1].name) > 0) {
                tmp = guests[i];
                guests[i] = guests[i + 1];
                guests[i + 1] = tmp;
            }
        }
    }
    
    return;
}