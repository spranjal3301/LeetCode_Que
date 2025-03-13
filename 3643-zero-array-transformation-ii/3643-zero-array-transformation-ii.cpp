class Solution {
    int n ;
    bool fn(vector<int>& nums,vector<vector<int>>& q,int k){
        vector<int> ps(n+1,0);

        for(int i=0;i<=k;i++){
            ps[q[i][0]]+=q[i][2];
            ps[q[i][1]+1]-=q[i][2];
        }

        for(int i=1;i<n+1;i++){
            ps[i] = ps[i-1] + ps[i];
        }

        for(int i=0;i<n;i++){
            int maxi = nums[i]-ps[i];
            if(maxi>0)return false;
        }

        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
      n = nums.size(); 

      bool chk = 1;  
      for(int i=0;i<n;i++){
        if(nums[i]!=0)chk = 0;
      }

      if(chk)return 0;

      int l = 0;
      int h = q.size() - 1; 
      int res = -1;

      while(l<=h){
        int mid = (l+h)/2;

         if(fn(nums,q,mid)){
            // cout<<mid<<" ";
            res = mid + 1;
            h = mid - 1;
         }else{
            l = mid + 1;
         }
      }

    //   for(int i=0;i<q.size();i++){
    //     if(fn(nums,q,i))return i+1;
    //   } 

      return res;
    }
};
