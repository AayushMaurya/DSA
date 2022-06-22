// Course Schedule
// Using Khaden's algorithm

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

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        
        for(auto itr: prerequisites){
            indegree[itr[1]]++;
            adj[itr[0]].push_back(itr[1]);
        }
        
        queue<int> q;
        int ans=0;
        
        for(int i=0; i<indegree.size(); i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            ans++;
            
            for(auto itr: adj[node])
            {
                indegree[itr]--;
                if(indegree[itr]==0)
                    q.push(itr);
            }
        }
        
        if(ans<numCourses)
            return false;
        
        return true;
    }