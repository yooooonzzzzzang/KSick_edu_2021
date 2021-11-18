#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define FR_FNAME "friend.dat"

typedef struct{
        int age;
        char name[10];
        char addr[256];
        char email[256];
        char phone[16];
}FRIEND_T;

