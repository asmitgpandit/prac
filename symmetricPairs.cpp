#include <iostream>
#include <unordered_set>
#include<vector>
using namespace std;

int main()
{
	vector<pair<int,int>> parr = {
							{3,4},
							{2,1},
							{5,4},
							{1,2},
							{7,2},
							{4,3},
						};

	struct PairHasher
	{
		size_t operator()(const pair<int,int> &mypair) const
		{
			return ((mypair.first * 3) + 62);
		}
	};


	unordered_set<pair<int,int>,PairHasher> uset;

	for(auto a: parr)
	{
		if (uset.find(a) == uset.end())
			uset.insert(make_pair(a.second,a.first));
		else
		{
			cout<<"pair is : {"<<a.first<<","<<a.second<<"} and {"<<a.second<<","<<a.first<<"}"<<endl;
		}
	}



	return 0;
}