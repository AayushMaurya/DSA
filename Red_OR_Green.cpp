#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	string str;
	cin>>str;

	int r=0, g=0;

	for (int i = 0; i < n; ++i)
	{
		if(str[i] == 'R')
			r++;
		else if(str[i] == 'G')
			g++;
	}

	int res = (r<g) ? r : g;

	cout<<res<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}