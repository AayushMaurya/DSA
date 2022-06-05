// Count Number of Rectangles Containing Each Point

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

vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> ans;
        
        vector<vector<int>> height(101);
        
        for(auto &i:rectangles)
            height[i[1]].push_back(i[0]);
        
        for(auto &i: height)
            sort(i.begin(), i.end());
        
        for(auto &p: points)
        {
            int count = 0;
            
            for(int i=p[1]; i<=100; i++)
            {
                count += (height[i].end() - lower_bound(height[i].begin(), height[i].end(), p[0]));
            }
            
            ans.push_back(count);
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