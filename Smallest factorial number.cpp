// Smallest factorial number

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

int findNum(int n)
        {
            if(n <= 4)
                return 5*n;
            
            int right = n*5;
            int left = 1;
            int ans = INT_MAX;
            
            while(left<=right)
            {
                int mid = (left+right)/2;
                int temp = mid;
                
                int count=0;
                while(temp/5)
                {
                    count+=temp/5;
                    temp = temp/5;
                }
                
                if(count < n){
                    left = mid+1;
                }
                else{
                    
                    ans = min(ans, mid);
                    right = mid-1;
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