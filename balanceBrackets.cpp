#include <iostream>
#include <stack>
using namespace std;

bool arePairs(const char c1, const char c2)
{
	if (c1 == '{' && c2 == '}')
		return true;
	else if (c1 == '[' && c2 == ']')
		return true;
	else if (c1 == '(' && c2 == ')')
		return true;
	else return false;
}


bool isBalanced(string &s)
{
	stack<char> stk;
	for (int i=0; i<s.length(); i++)
	{
		if ((s[i] == '{') || (s[i] == '[') || (s[i] == '('))
			stk.push(s[i]);
		else
		{
			if (stk.empty() || !arePairs(stk.top(), s[i]))
				return false;
			else
				stk.pop();
		}
	}
	if (stk.empty())
		return true;
	else 
		return false;
}


int main()
{
	string s = "{[(])]}";

	if (isBalanced(s))
		cout<< "Yes !";
	else
		cout<< "No";

	return 0;
}