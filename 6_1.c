#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
	struct car{
		char name[10];
		int year;
		double fuel;
	};
	struct car sonata;

	strcpy(sonata.name, "SONATA");
	sonata.year =2003;
	sonata.fuel =77.7;

	printf("%s : %d year %g fuel\n", sonata.name, sonata.year, sonata.fuel);
}

