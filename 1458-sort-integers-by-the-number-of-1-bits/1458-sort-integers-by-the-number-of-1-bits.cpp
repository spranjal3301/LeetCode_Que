class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
         map<int,multiset<int>> mms;

        for(int i=0;i<arr.size();i++){
            int count=0;
            for(int b=0;b<32;b++)if((arr[i]>>b)&1)count++;

            mms[count].insert(arr[i]);
        }
        int i=0;
        for(auto &m:mms){
            for(auto &ms:m.second){
                arr[i]=ms;
                i++;
            }
        }
        return arr;

    }
};