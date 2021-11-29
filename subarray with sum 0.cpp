// Find if there is a sub array with sum equals to 0

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back


void solve()
{
	int n;
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++)
        cin>>arr[i];

    unordered_set<int> s;
    int sum = 0;
    for(int i=0 ; i<n ; i++)
    {
        sum += arr[i];

        if(sum==0 || s.find(sum) != s.end())
        {
            cout<<"True"<<endl;
            return;
        }

        s.insert(sum);
    }
    cout<<"False"<<endl;
    return;
}

int main()
{
	solve();
	return 0;
}