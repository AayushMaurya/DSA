// Merge Two sorted arrays
// Space O(1)
// Time O(n*m)

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

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j=0;
        if(n==0)
            return;
        for(i=0; i<m; i++)
        {
            
            if(nums1[i]<=nums2[j])   continue;
            else{
                swap(nums1[i], nums2[0]);
                int x=0;
                while(x+1<n && nums2[x]>nums2[x+1])
                {
                    swap(nums2[x], nums2[x+1]);
                    x++;
                }
                i--;
            }
        }
        while(j<n)
        {
            nums1[i] = nums2[j];
            i++;
            j++;
        }
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}