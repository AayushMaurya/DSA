// Possible Bipartition

#include <bits/stdc++.h>
using namespace std;

bool check(int node, vector<int> graph[], vector<int>& color)
    {
        queue<int> q;
        q.push(node);

        color[node] = 1;

        while(!q.empty())
        {
            int temp = q.front();
            q.pop();

            for(auto itr: graph[temp])
            {
                if(color[itr] == -1)
                {
                    color[itr] = 1-color[temp];
                    q.push(itr);
                }
                else if(color[itr] == color[temp])
                    return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<int> graph[n];

        for(int i=0; i<dislikes.size(); i++)
        {
            graph[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            graph[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }

        vector<int> color(n, -1);

        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
            {
                if(!check(i, graph, color))
                    return false;
            }
        }

        return true;
    }

int main()
{
	solve();
	return 0;
}