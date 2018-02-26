#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string &s1, string &s2)
{
	// if (s1.length() != s2.length())
	// 	return false;

	unordered_map<char,int> m1, m2;

	for(int i=0; i<s1.length(); i++)
		m1[s1[i]]++;
		
	for(int i=0; i<s2.length(); i++)
		m2[s2[i]]++;

	m1.erase(' ');
	m2.erase(' ');

	unordered_map<char,int>::iterator it = m1.begin();

	while(it != m1.end())
	{
		if (m2[it->first] != it->second)
			return false;
		//cout<<it->first<<it->second<<endl;
		it++;
	}
	return true;
}

int main()
{
	string s1 = "Asmit";
	string s2 = "A smit";

	if(isAnagram(s1,s2))
		cout<<"Is Anagram !"<<endl;
	else
		cout<<"Not an Anagram !"<<endl;
	
	return 0;
}