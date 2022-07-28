#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int>& nums)
{
    int n = nums.size();
    int start = 0, end = n-1;

    while(start < end)
    {
        int mid = start + (end-start)/2;

        if(nums[mid] >= nums[0])
            start = mid+1;
        else 
            end = mid;
    }

    return start;
}

int binarySearch(vector<int>& nums, int start, int end, int target)
{
    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(nums[mid] == target)
            return mid;
        else if(target > nums[mid])
            start = mid+1;
        else 
            end = mid-1;
    }

    return -1;
}

int searchInRotatedArray(vector<int>& nums, int target)
{
    int n = nums.size();
    int pivot = getPivot(nums);

    if(target >= nums[pivot] && target <= nums[n-1])
        return binarySearch(nums, pivot, n-1, target);
    else
        return binarySearch(nums, 0, pivot-1, target);

    return -1;
}