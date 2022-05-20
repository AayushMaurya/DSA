#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	
	int index = 0, n = s.length();
	for(int i=0 ; i<n ; i++)
	{
		if(s[i] == ' ')
		{
			s[i+1] = toupper(s[i+1]);
			continue;
		}
		else
			s[index++] = s[i];
	}

	cout<<s.substr(0, index)<<endl;
	return 0;
}