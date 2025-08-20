class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int sum = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    dp[i][j] = mat[i][j] + (i-1<0 || j-1<0 ? 0 :
                               min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}));
                }
                sum+=dp[i][j];
            }
        }
        




        return sum;
    }
};