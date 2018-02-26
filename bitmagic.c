#include<stdio.h>
#include<stdint.h>

int noSetBits(uint32_t number)
{
	int count=0;
	while(number)
	{
		count++;
		number = (number-1) & number;
	}
	return count;
}

int noBitFlips(uint32_t a, uint32_t b)
{
	int distinct_bits = (a ^ b);
	return noSetBits(distinct_bits);
}

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int isPower2(int n)
{
	if (!n) return 0;
	return ((n-1) & n) ? 0 : 1;
}

int rightmostSetBitPos(uint32_t num)
{
	int count=0;
	int res=0;

	while(num)
	{
		count++;
		if (num & 1)
			return count;
		num = num >> 1;
	}
}


int main()
{
	int x =15;
	int y = 10;
	// printf("No of bit flips = %d\n",noBitFlips(x,y));
	// swap(&x,&y);
	// printf("x= %d\ty= %d\n",x,y);
	// printf("isPower2(64) = %d\n",isPower2(64));
	// printf("isPower2(0) = %d\n",isPower2(0));

	rightmostSetBitPos(64);
	printf("rightmostSetBitPos(64) = %d\n",rightmostSetBitPos(8));

	return 0;
}