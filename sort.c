#include "sort.h"

void sort(Artist* artists, int size)
{
    Artist tmp;
    for (int j = 0; j < size-1; j++) {
        for (int i = 0; i < size-1; i++) {
            if(strcmp(artists[i].name, artists[i + 1].name) > 0) {
                tmp = artists[i];
                artists[i] = artists[i + 1];
                artists[i + 1] = tmp;
            }
        }
    }
    
    return;
}