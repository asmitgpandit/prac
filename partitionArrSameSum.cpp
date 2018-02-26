#include <iostream>
#include <vector>
using namespace std;
int sum(int start, int end, vector<int> &myV)
{
	int sum = 0;
	for(int i=start; i<=end; i++)
	{
		sum = sum + myV[i];
	}
	return sum;
}

void printArr(int end, vector<int> &myV)
{
	cout<<"First Sub-Array : { ";
	for(int i=0; i<=end; i++)
		cout<<myV[i]<<" ";
	cout<<"}\n";

	cout<<"Second Sub-Array : { ";
	for(int i=end+1; i<=myV.size()-1; i++)
		cout<<myV[i]<<" ";
	cout<<"}\n";
}

int main()
{
	std::vector<int> myV = {6,-5,2,-4,1};
	int sum1 = 0;
	int sum2 = 0;
	int total_sum = sum(0,myV.size()-1,myV);
	int end = 0;

	for(int i=0; i<myV.size(); i++)
	{
		sum1 = sum1 + myV[i];
		sum2 = total_sum - sum1;

		if (sum1 == sum2)
		{
			printArr(i,myV);
			return 0;
		}
	}
	cout<<"Can't be partitioned into equal sub-arrays"<<endl;

	return 0;
}