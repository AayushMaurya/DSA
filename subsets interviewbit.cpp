// Subsets
// Elements in a subset must be in non-descending order.
// Also, the subsets should be sorted in ascending ( lexicographic ) order.

#include <bits/stdc++.h>
using namespace std;


void solve(vector<int>& nums, int index, vector<int>& res, vector<vector<int>>& ans)
{
	ans.push_back(res);

	for(int i=index; i<nums.size(); i++)
	{
		res.push_back(nums[i]);
		solve(nums, i+1, res, ans);
		res.pop_back();
	}

	return;
}

vector<vector<int>> subsets(vector<int> nums)
{
	sort(nums.begin(), nums.end());

	vector<int> res;
	vector<vector<int>> ans;

	solve(nums, index, res, ans);

	return ans;
}