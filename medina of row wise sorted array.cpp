// Median of row wise sorted array

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

int median(vector<vector<int>> &matrix, int r, int c){
        
        int left = INT_MAX, right = INT_MIN;
        
        int ans=0;
        int place = (r*c + 1)/2;
        
        for(int i=0; i<r; i++)
        {
            left = min(left, matrix[i][0]);
            right = max(right, matrix[i][c-1]);
        }
                  
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            
            int count=0;
            
            for(int i=0; i<r; i++)
                count += (upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin());
            if(count >= place)
            {
                ans = mid;
                right = mid-1;
            }
            else
                left = mid+1;
        }
        
        return ans;
    }