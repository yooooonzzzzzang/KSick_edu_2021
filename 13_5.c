#include <stdio.h>
#include <search.h>

int main(int argc, char**argv)
{
	ENTRY item;
	ENTRY *result;
	hcreate(5);
	item.key ="Linux";
	item.data="Linux";
	hsearch(item,ENTER);
	item.key="C";
	item.data="C";
	hsearch(item,ENTER);
	item.key="Programming";
	item.data="Programming";
	hsearch(item, ENTER);

	item.key="Linux";
	item.data="Linux";

	if((result=hsearch(item, FIND)) ==NULL)
		printf("Not found\n");
	else
		printf("Found : %s\n", (char *)item.data);

	item.key ="Java";
	item.data ="Java";
	if((result= hsearch(item, FIND)) ==NULL)
		printf("Not found\n");
	else
		printf("Found : %s\n", (char *)result->data);
}

