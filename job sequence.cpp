// Job sequence problem

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
ll max(ll x, ll y)
{
    return (x>y)?x:y;
}
ll min(ll x, ll y)
{
    return (x>y)?y:x;
}
void swap(ll *x, ll *y)
{
    ll temp = *x;
    *x = *y;
    *y = temp;
}

struct Job {
    int id;
    int dead;
    int profit;
};

vector<int> JobScheduling(Job arr[], int n) 
{ 
        vector<pair<int, int>> job;
        
        for(int i=0 ; i<n ; i++)
            job.push_back({arr[i].profit, arr[i].dead});
        
        sort(job.rbegin(), job.rend());
        
        int sum=0, count=0;
        
        int maxD = INT_MIN;
        for(int i=0 ; i<n ; i++)
            maxD = max(maxD, job[i].second)
        
        int seq[maxD+1];
        memset(seq, -1, sizeof(seq));

        for(int i=0 ; i<n ; i++)
        {
            for(int j=job[i].second ; j>=0 ; j--)
            {
                if(seq[j] == -1)
                {
                    seq[j] = 1;
                    sum+=job[i].first;
                    count++;
                    break;
                }
            }
        }
        
        return {count, sum};
}

void solve()
{

    int n;
    cin>>n;

    Job arr[n];

    for(int i=0 ; i<n ; i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        arr[i].id=x;
        arr[i].dead = y;
        arr[i].profit = z;
    }

    vector<int> res = JobScheduling(arr, n);

    cout<<res[0]<<" "<<res[1]<<endl;

    return;
}

int main(){
    solve();
    return 0;
}