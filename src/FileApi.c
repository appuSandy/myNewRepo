#include "FileApi.h"

int ReadFile(char * path, char** string) {

	int bufferSize = 0, ret = 0;

	FILE *f1;

	f1 = fopen(path, "r");
	if (f1 == NULL) {
		perror("error in opening file\n");
		exit(EXIT_FAILURE);
	}

	fseek(f1, 0, 2);
	bufferSize = (int) ftell(f1);

	*string = malloc((bufferSize * sizeof(char)) + 1);

	rewind(f1);

	ret = fread(*string, 1, bufferSize, f1);

	if (bufferSize == ret) {
		printf("string: %s \n", *string);
	} else {
		printf("ret : %d !=  buffersize : %d \n", ret, bufferSize);
	}
	fclose(f1);

	return ret;
}

int FindExt(char *fileName, char *str) {
	char *ptr;
	int i = 0;
	ptr = strchr(fileName, '.');
	ptr++;
	i = 0;
	while (*ptr) {
		str[i++] = *(ptr++);
	}
	str[i] = NULL;
}

int IsFile(char *fileName)
{
	DIR* directory = opendir(fileName);

	if (directory != NULL)
	{
		closedir(directory);
		return 0;
	}

	if (errno == ENOTDIR)
	{
		return 1;
	}
	else
	{
		perror(" unknown error\n");
		return -1;
	}
}
