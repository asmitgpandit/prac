#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
	vector<int> v1 = {1,3,5,4,8,2,4,3,6,5};

	int m = 3;
	int n = 8;

	int last_start = 0;
	int last_end = v1.size() -1;
	int start = 0;
	int end = 0;
	int last_seen = 0;

	for(int i=0; i< v1.size(); i++)
	{
		if ((v1[i] == m) || (v1[i] == n))
		{
			if (last_seen == 0)
			{
				last_seen = v1[i];
				start = i;
				continue;
			}
			
			if (last_seen != v1[i])
			{
				end = i;
				if ((end - start) < (last_end - last_start))
				{
					last_end = end;
					last_start = start;
				}
				last_seen = v1[i];

			}
			start = i;

		}
	}
	cout<<"Min difference between 2 index is : "<<(last_end - last_start)<<endl;
}

