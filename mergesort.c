#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int l, int m, int r)
{
	int size = r-l+1;
	int sizel = m-l+1;
	int sizer = r-m;
	int i=l,j=m+1,k=0;
	
	
	printf("size=%d, sizel=%d, sizer=%d\n",size,sizel,sizer);
	
	int *new_arr = (int *)malloc(size * sizeof(int));
	
	for(; (i<=m)&&(j<=r); k++)
	{
		if (arr[i] <= arr[j])
		{
			new_arr[k] = arr[i];
			i++;
		}
		else
		{
			new_arr[k] = arr[j];
			j++;
		}
	}
	if(i<(m+1))
	{
		while(i<(m+1))
		{
			new_arr[k] = arr[i];
			k++;
			i++;
		}
	}
	if(j<(r+1))
	{
		while(j<(r+1))
		{
			new_arr[k] = arr[j];
			k++;
			j++;
		}
	}
	
	//Copy new_arr into original arr
	for(int a=0; a<size; a++)
	{
		arr[a] = new_arr[a];
	}
	free(new_arr);
}

int main()
{
	int arr[] = {11, 12, 13,  14, 5, 10, 19, 200};
	int size = sizeof(arr)/sizeof(arr[0]);
	int l=0, r=size-1;
	int mid = l + ((r-l)/2);
	merge(arr,0,mid,size-1);
	
	printf("Merged array = [ ");
	for(int i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("]\n");

}