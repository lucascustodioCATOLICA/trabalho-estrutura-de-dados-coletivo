#ifndef TYPES
#define TYPES

#define MAX_LENGTH 99

struct Album {
    char name[64];
} typedef Album;

struct Artist {
    char name[64];
    char gender[64];
    char bornAt[64];
    Album albums[64];
    int albumsSize;
} typedef Artist;

#endif