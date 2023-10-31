class Solution {
int Binary_Search(vector<int>& arr, int key)
{
    int n=arr.size();
    int start = 0;
    int end = n - 1;
    if (key > arr[end] or key < arr[start])
    {
        return -1;
    }
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size()-1;
        if(target<nums[0])return 0;
        else if(target>nums[n])return n+1;
        return Binary_Search(nums,target);

    }
};