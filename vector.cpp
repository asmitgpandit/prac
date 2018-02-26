// vector::data
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  std::vector<int> myvector = {6,3,9,2,4,2,1,7};
  std::vector<int> v1;
  std::vector<int> v2;
  int turn = 0;

  sort(myvector.begin(), myvector.end(), greater<int>());

  for(auto a: myvector)
  {
    if (turn == 0)
    {
      v1.push_back(a);
      turn = 1;
    }
    else if (turn == 1)
    {
      v2.push_back(a);
      turn=0;
    }

  }
  
  cout<<"v1 = ";
  for(auto a: v1)
    cout<<a;

  cout<<endl;

  cout<<"v2 = ";
  for(auto a: v2)
    cout<<a;

  return 0;
}