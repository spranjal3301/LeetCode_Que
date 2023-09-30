class Solution {
public:
    void merge(vector<int> &arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];
    int k = start;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[k++];
    }

    k = start;
    int i = 0, j = 0;

    while (len1 > i and len2 > j)
    {
        if (arr1[i] > arr2[j])
        {
            arr[k++] = arr2[j++];
        }
        else
        {
            arr[k++] = arr1[i++];
        }
    }

    while (len1 > i)
    {
        arr[k++] = arr1[i++];
    }
    while (len2 > j)
    {
        arr[k++] = arr2[j++];
    }

    delete[] arr1;
    delete[] arr2;
}
void MergeSort(vector<int> &arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (start >= end)
    {
        return;
    }

    //! Sort left part
    MergeSort(arr, start, mid);

    //! Sort Right part
    MergeSort(arr, mid + 1, end);

    //! merge Left & Right Part
    merge(arr, start, end);
}
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums, 0,nums.size()-1);
        return nums;
    }
};