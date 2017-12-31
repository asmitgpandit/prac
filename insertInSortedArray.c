#include<stdio.h>
#include<stdlib.h>


void print(int *arr, int len)
{
	int i=0;
	printf("\n{");
	for(;i<len;i++)
		printf(" %d ",arr[i]);
	printf("}\n");
}

void bubbleSort(int *arr, int len)
{
	int i,j,temp=0;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}

	}
}

void insertionSort(int *arr, int len)
{
	int i,j,temp=0;

	for(i=1;i<len;i++)
	{
		for(j=i;j>0;j--)
		{
			if (arr[j] < arr[j-1])
			{
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
			else
				break;
		}
	}
}

void mergeSort(int *arr, int l, int r)
{
	int i,j,k;

	int *pArr = NULL;
	int size = r-l+1;
	int mid = l + (r-l)/2;

	if((l==mid)||((mid+1)==r))
		return;
	printf("\nl = %d\tr = %d\tmid = %d\tsize = %d",l,r,mid,size);
	//call mergeSort on the 2 subarrays
	mergeSort(arr,l,mid);
	mergeSort(arr,mid+1,r);
	

	/*pArr = (int *)malloc(sizeof(int)*size);

	//Now merge 2 sorted subarrays
	for(i=l,j=mid+1,k=0; (i<=mid)||(j<=r); )
	{
		if(arr[i]<=arr[j])
		{
			pArr[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			pArr[k] = arr[j];
			j++;
			k++;
		}
	}
	if (i<=mid)
	{	
		while(i<=mid)
		{
			pArr[k] = arr[i];
			i++;
			k++;
		}
	}
	if (j<=r)
	{
		while(j<=r)
		{
			pArr[k] = arr[j];
			j++;
			k++;
		}
	}

	//Copy in origninal arr and free pArr
	for(i=0,k=0;i<size;i++,k++)
		arr[i] = pArr[k];*/

}

int main()
{
	int arr[] = {5,1,55,2,98,10,4,3,8,22};
	int len = sizeof(arr)/sizeof(arr[1]);
	print(arr,len);
	//bubbleSort(arr,len);
	//insertionSort(arr,len);
	mergeSort(arr,0,len-1);
	print(arr,len);

}