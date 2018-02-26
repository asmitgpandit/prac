#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;


class base
{
public:
	static const int i = 100;
};



int main()
{
	unordered_map<int, void *> umap;
	// umap.insert(2,make_pair(20,1));
	// umap.insert(3,make_pair(30,111));
	// umap.insert(4,make_pair(40,9));
	// umap.insert(5,make_pair(50,10));
	// umap.insert(6,make_pair(60,6));
	umap.insert(make_pair(20,(void *)1));
	cout<<umap.size();
	
	return 0;
}