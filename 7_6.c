#include <stdio.h>
#define NAME

int main(int argc, char**argv)
{
#ifdef NAME
	printf("NAME defined\n");
#endif

#ifndef NAME
	printf("NAME undefined\n");
#endif

#ifndef ADDRESS
        printf("ADDRESS undefined\n");
#endif  
        
}

