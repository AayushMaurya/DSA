// Nearly sorted

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

vector <int> nearlySorted(int arr[], int num, int K){
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<num; i++)
        {
            pq.push(arr[i]);
            if(pq.size()>K)
            {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}