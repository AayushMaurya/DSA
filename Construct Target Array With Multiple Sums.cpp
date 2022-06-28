// Construct Target Array With Multiple Sums

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

bool isPossible(vector<int>& target) {
        
        if(target.size() == 1)
            return target[0]==1;
        
        priority_queue<int> q;
        long long int sum = 0;
        
        for(auto itr: target){
            q.push(itr);
            sum += itr;
        }
        
        while(!q.empty())
        {
            cout<<q.size()<<" ";
            int curr = q.top();
            q.pop();
            cout<<curr<<" ";
            
            cout<<sum<<" ";
            sum = sum-curr;
            
            if(sum==1 || curr==1)
                return true;
            
            if (curr < sum || sum < 1) return false;
            
            int prev = curr%sum;
            
            sum += prev;
            if(prev > 1)
                q.push(prev);
            else if(prev == 0)
                q.push(sum);
            cout<<prev<<" "<<endl;
            
        }
        
        return true;
    }