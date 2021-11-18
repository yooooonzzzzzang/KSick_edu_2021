#include <stdio.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char**argv)
{
	uid_t uid;
	struct passwd *pw;

	uid = getuid();
	pw = getpwuid(uid);

	printf("name : %s, uid: %d, gid: %d, home: %s\n", pw->pw_name, pw-> pw_uid, pw->pw_gid, pw-> pw_dir);
	exit(0);
}

