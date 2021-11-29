#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define FR_FNAME "Finfo.dat"

typedef struct{
        char age[10];
        char name[10];
        char addr[256];
        char email[256];
        char phone[16];
}FRIEND_T;
       
