class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int maxi = 0;

        for(int i=1;i<=n;i++){
            int x = i;
            int sum = 0;
            
            while(x != 0){
                sum += (x%10);
                x/=10;
            }
            mp[sum]++;
            // cout<<sum<<" ";
            maxi = max(mp[sum],maxi);
        }

        int res = 0;
        for(auto [f,s]:mp){
            if(s == maxi)res++;
        }

        return res;
    }
};
// 1 10 ,2 11 ,3 12,4 13,5 14,6 15 ,7 16,8 17, 9 18 , 10