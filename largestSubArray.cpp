#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


int main()
{
	vector<int> v1 = {8,3,1,5,7,5,2,3,7,0,1,4,3,10,55,6,9,4,20,23,45,62};	//{2,0,2,1,4,3,1,0};
	int largest_start = 0;
	int largest_end = 0;
	int start = 0;
	int end = 0;
	int largest_seq_size = end - start;

	unordered_set<int> visited;

	for(int i=0; i< v1.size(); i++)
	{
		if (visited.find(v1[i]) == visited.end())
		{
			visited.insert(v1[i]);
			end = i;
		}
		else
		{
			//cout<<endl<<"DEBUG : "<<"i = "<<i<<"\tv1[i] = "<<v1[i]<<endl;
			visited.clear();
			visited.insert(v1[i]);

			if ((end - start + 1) > largest_seq_size)
			{
				largest_seq_size = end - start + 1;
				largest_start = start;
				largest_end = end;
			}
			start = i;
			end = i;
		}
	}

	if ((end - start + 1) > largest_seq_size)
	{
		largest_seq_size = end - start + 1;
		largest_start = start;
		largest_end = end;
	}	
	
	cout<<"largest Sub-array has size = "<<largest_seq_size<<endl;
	cout<<"Sub array = [ ";

	for(int i = largest_start; i<= largest_end; i++)
		cout<<v1[i]<<" ";
	cout<<"]"<<endl;

	return 0;
}