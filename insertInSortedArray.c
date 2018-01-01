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

void merge(int *arr1,int len1, int *arr2, int len2, int *pArr)
{
	int i, j, k=0;

	for(i=0,j=0; (i<len1)&&(j<len2);)
	{
		if(arr1[i] <= arr2[j])
		{
			pArr[k] = arr1[i];
			i++; k++;
		}
		else
		{
			pArr[k] = arr2[j];
			j++; k++;
		}
	}
	if(i<len1)
	{
		while(i<len1)
		{
			pArr[k] = arr1[i];
			i++; k++;
		}
	}

	if(j<len2)
	{
		while(j<len2)
		{
			pArr[k] = arr2[j];
			j++; k++;
		}
	}

	//print pArr
	// for(k=0; k<(len1+len2); k++)
	// {
	// 	printf(" %d ",pArr[k]);
	// }
}

void mergeSort(int *arr, int l, int r)
{
	int i,j,k, len1, len2;

	int *pArr = NULL;
	int size = r-l+1;
	int mid = l + (r-l)/2;
	len1 = mid - l + 1;
	len2 = r - mid;

	
	if(l==r)
		return;
	
	pArr = (int *)malloc(sizeof(int)*size);

	mergeSort(arr,l,mid);
	mergeSort(arr,mid+1,r);
	
	
	merge(arr+l, len1, arr+mid+1, len2, pArr);

	//Copy in origninal arr and free pArr
	for(i=0,j=l,k=0;i<size;i++,j++,k++)
	{
		arr[j] = pArr[k];
	}
	
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