// Find union and intersection of given two arrays 

#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m;
	cin>>n>>m;
	int a[n], b[m];
	for(int i=0 ; i<n ; i++)
		cin>>a[i];
	for(int i=0 ; i<m ; i++)
		cin>>b[i];
	
	// does not required if the arrays are already sorted
	sort(a, a+n);
	sort(b, b+m);
	
	set<int> s(a, a+n);

	for(int i=0 ; i<m ; i++)
		s.insert(b[i]);

	cout<<"The union of the given arrays :"<<endl;
	for(auto itr = s.begin() ; itr!=s.end() ; itr++)
		cout<<*itr<<" ";
	cout<<endl;

	vector<int> v;
	
	int i=0, j=0;
	while(i < n && j < m)
	{
		if(a[i] == b[j])
		{
			v.push_back(a[i]);
			i++;
			j++;
		}
		else if(a[i] > b[j])
			j++;
		else if(a[i] < b[j])
			i++;
	}

	cout<<"The intersection of the given arrays is :"<<endl;
	for(auto itr=v.begin() ; itr!=v.end() ; itr++)
		cout<<*itr<<" ";
	cout<<endl;
	
	return;
}

int main()
{
	solve();
	return 0;
}