#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string str;
	cin>>str;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	cout<<str<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}