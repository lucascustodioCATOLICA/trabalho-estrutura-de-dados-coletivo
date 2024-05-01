#ifndef TYPES
#define TYPES

#define ROOMS_LENGTH 40
#define MAX_LENGTH 99

struct Guest {
    char name[64];
    char gender;
    int age;
    int roomIndex; // 0 - 39: indicates which room the guest is using.
} typedef Guest;

#endif