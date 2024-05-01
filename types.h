#ifndef TYPES
#define TYPES

#define ROOMS_LENGTH 26
#define MAX_GUESTS_LENGTH 99

struct Guest {
    char name[64];
    char gender;
    int age;
    char roomId; // A - Z: indicates which room the guest is using.
} typedef Guest;

#endif