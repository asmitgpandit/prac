#include <stdio.h>



int memscpy(char *dest, int dest_size, char *source, int src_size)
{
	int i;

	if (src_size > dest_size)
		return -1;

	for(i=0; i<src_size; i++)
	{
		(dest[i]) = (source[i]);
	}
	return i;
}

int main()
{
	char buffer[5];
	char str1[] = "Hello";

	memscpy(buffer,5, str1,5);
	printf("%s\n",buffer);
	return 0;
}