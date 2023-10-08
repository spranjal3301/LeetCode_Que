class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(nums[0]);
        pq.push(nums[1]);

        for(int i=2;i<nums.size();i++){
            if(pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        int a=pq.top()-1;
        pq.pop();
        int b=pq.top()-1;
        return a*b;
    }
};