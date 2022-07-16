// Matchsticks to Square

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
# define pii pair<int, int>
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

 bool solve(int index, vector<int>& ms, int s1, int s2, int s3, int s4, int total)
    {
        if(s1==total && s2==total && s3==total && s4==total)
            return true;
        
        if(s1+ms[index] <= total)
        {
            if(solve(index+1, ms, s1+ms[index], s2, s3, s4, total))
                return true;
        }
        if(s2!=s1 && s2+ms[index]<=total)
        {
            if(solve(index+1, ms, s1, s2+ms[index], s3, s4, total))
                return true;
        }
        if(s3!=s1 && s3!=s2 && s3+ms[index]<=total)
        {
            if(solve(index+1, ms, s1, s2, s3+ms[index], s4, total))
                return true;
        }
        if(s4!=s1 && s4!=s2 && s4!=s3 && s4+ms[index]<=total)
        {
            if(solve(index+1, ms, s1, s2, s3, s4+ms[index], total))
                return true;
        }
            
        return false;
    }
    
    bool makesquare(vector<int>& ms) {
        
        int sum=0;
        for(auto itr: ms)
            sum += itr;
        
        if(sum%4!=0)
            return false;
        
        sum = sum/4;
        
        return solve(0, ms, 0, 0, 0, 0, sum);
    }