// Merge Intervals

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

void solve()
{
	vector<vector<int>> intervals;
	int n, x, y;
	cin>>n;
	for(int i=0 ; i<n ; i++){
		vector<int> temp;
		cin>>x>>y;
		temp.pb(x);
		temp.pb(y);
		intervals.pb(temp);
	}

	sort(intervals.begin(), intervals.end());

	// cout<<"[";
	// for(int i=0 ; i<n ; i++)
	// {
	// 	cout<<"["<<intervals[i][0]<<","<<intervals[i][1]<<"]"<<", ";
	// }
	// cout<<"]"<<endl;

	vector<vector<int>> mergedInterval;
        
    if(intervals.size() == 0)
        return;
        
    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];
        
    for(auto it : intervals)
    {
        if(it[0] <= tempInterval[1])
            tempInterval[1] = max(it[1], tempInterval[1]);
        else{
            mergedInterval.push_back(tempInterval);
            tempInterval = it;
        }
    }
    
    mergedInterval.push_back(tempInterval);

	// cout<<"["<<"["<<mergedInterval[0][0]<<","<<mergedInterval[0][1]<<"]";
	for(auto it : mergedInterval)
	{
		cout<<", "<<"["<<it[0]<<","<<it[1]<<"]";
	}
	cout<<"]"<<endl;

	return;
}

int main()
{
	solve();
	return 0;
}