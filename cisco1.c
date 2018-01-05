#include <stdio.h>


#define max_seq_size 20


int is_present(int target, int *arr2,int len_arr2)
{
	for(int i=0; i<len_arr2; i++)
	{
		if (arr2[i] == target)
			return 1;
	}
	return 0;
}

int main()
{
	int arr1[] = {2,3,5,7,8,10,15,18,22,34,45,46,50,88};
	int arr2[] = {1,2,3,6,9,13,18,23,32,45,46,50,91,98,102};

	int len_arr1 = sizeof(arr1)/sizeof(int);
	int len_arr2 = sizeof(arr2)/sizeof(int);

	int target_seq_len = 0;
	int sequence[max_seq_size] 		= {0};
	int scratchpad[max_seq_size] 	= {0};
	int scratch_len = 0;

	for(int i=0; i<len_arr1; i++)
	{
		if(is_present(arr1[i], arr2, len_arr2))
		{
			//Insert this number to scratchpad to form a sequence
			scratchpad[scratch_len] = arr1[i];
			scratch_len++;
		}
		else
		{
			if (scratch_len > target_seq_len)
			{
				//copy sequence from the scratchpad to the sequence buffer
				for(int i=0; i<scratch_len; i++)
					sequence[i] = scratchpad[i];

				target_seq_len = scratch_len;
			}
			//flush the scratchpad and the scratch_len
			for(int i=0; i<max_seq_size; i++)
					scratchpad[i] = 0;
			scratch_len = 0;
			
		}
	}
	for(int i=0; i<target_seq_len; i++)
		printf(" %d ",sequence[i]);

	return 0;
}