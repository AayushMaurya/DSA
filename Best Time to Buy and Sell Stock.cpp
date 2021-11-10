// Best time to buy and sell stock

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back


void solve()
{
	int n;
	cin>>n;
	int price[n];
	for(int i=0 ; i<n ; i++)
		cin>>price[i];

	int min=price[0];
	int max = 0;

	for(int i=1 ; i<n ; i++)
	{
		int temp = price[i] - min;
		if(temp > max)
			max = temp;

		if(price[i] < min)
			min = price[i];
	}

	cout<<max<<endl;
}

int main()
{
	solve();
	return 0;
}