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

char *itoa(int num, char *buff, int base)
{
	buff[19] = '\0';
	int digit = 0;
	int i=18;
	int negative = 0;

	if (num <0)
	{
		num = 0-num;
		negative = 1;
	}

	for(;(num && i);i--)
	{
		digit =  num % base;
		num = num/base;
		buff[i] = '0' + digit;
	}

	if(negative)
		buff[i] = '-';
	else
		i++;

	for(int j=0;i<20;i++,j++)
		buff[j] = buff[i];
	return buff;
}


int main()
{
	// char buffer[5];
	// char str1[] = "Hello";

	// memscpy(buffer,5, str1,5);
	// printf("%s\n",buffer);

	char buff[20];
	printf("1527 is %s\n",itoa(1527,buff,10));
	return 0;
}