class Solution {
public:
   int getWinner(vector<int> &arr, int k)
{
    if(k>=arr.size())return *max_element(arr.begin(),arr.end());
    int cnt = 0;
    int a = arr[0];
    int i = 0;
    while (i < arr.size())
    {
        int j = i + 1;
        int b = arr[j];
        while (a > b)
        {
            cnt++;
            if (cnt == k)
                return a;
            arr.push_back(b);
            arr[j] = 0;
            j++;
            b = arr[j];
        }
        cnt = 1;
        if (cnt == k)return b;
        arr.push_back(a);
        arr[i] = 0;
        i = j;
        a = arr[i];
    }
    return 0;
}
};