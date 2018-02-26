#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = {2,2,2,3,3,4,4,4,4,4,5,5,7,8,9,9};
	unordered_map<int,int> umap;

	for(int i=0; i<v.size(); i++)
	{
		umap[v[i]]++;
	}

	for(auto a = umap.begin(); a != umap.end(); a++)
	{
		cout<<a->first<<" occurs "<<a->second<<" times."<<endl;
	}


	return 0;
}