// Majority element 
// Space O(1)

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

int majorityElement(vector<int>& nums) {
        int count=0;
        int element;
        for(int i=0; i<nums.size(); i++)
        {
            if(count==0){
                element = nums[i];
                count++;
            }
            else{
                if(nums[i] == element)
                    count++;
                else
                    count--;
            }
        }
        return element;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}