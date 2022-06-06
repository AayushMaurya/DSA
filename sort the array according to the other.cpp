// sort ans array according to the other

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

vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        map<int, int> pos;
        
        for(int i=0; i<N; i++)
            pos[A1[i]]++;
        
        vector<int> ans;
        
        for(int i=0; i<M; i++)
        {
            while(pos[A2[i]])
            {
                ans.push_back(A2[i]);
                pos[A2[i]]--;
            }
        }
        for(auto itr: pos)
        {
            while(itr.second)
            {
                ans.push_back(itr.first);
                itr.second--;
            }
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