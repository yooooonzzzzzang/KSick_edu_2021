#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define FR_FNAME "Finfo2.dat"

typedef struct{
        int age;
        char name[10];
        char address[256];
        char email[256];
        char phone[16];
}FRIEND_T;

