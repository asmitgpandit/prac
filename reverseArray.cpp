#include <iostream>
using namespace std;

void reverseArray(int arr[], int n)
{
	int end = n-1;
	int temp = 0;
	for(int i=0; i<n/2;i++)
	{
		temp = arr[i];
		arr[i] = arr[end-i];
		arr[end-i] = temp;
	}
}

void reverseArrayRecursive(int arr[], int n, int i)
{
	if (i == (n/2))
		return;

	int end = n-1;
	int temp = arr[i];
	arr[i] = arr[end-i];
	arr[end-i] = temp;
	reverseArrayRecursive(arr, n, i+1);
}

int main()
{
	int arr[] = {1,2,3,4,5};

	//reverseArray(arr, sizeof(arr)/sizeof(arr[0]));
	reverseArrayRecursive(arr,sizeof(arr)/sizeof(arr[0]),0);

	for(auto a: arr)
	{
		cout<< a <<"\t";
	}
}