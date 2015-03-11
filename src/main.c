#include "main.h"

int main()
{
	char *path = "/home/radix/Project/samples/practice/src/practice/";
	char *string = NULL;
	char ext[5];
int ret;
	/*	if(ReadFile(path, &string))
	{
		printf("str : %s", string);
	}
*/
/*	FindExt("sandeep.txt",ext);
	printf("str : %s", ext);
*/
	ret = IsFile(path);
	if(ret == 1)
	{
		printf("its a file %d \n", ret);
	}
	else if(ret == 0)
	{
		printf("its a directory %d \n", ret);
	}
}
