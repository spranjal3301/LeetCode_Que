class Solution {
    bool isPalindrome(string s){
        int i=0;
        int j=s.size()-1;
        while(j>=i){
            if(s[j--]!=s[i++])return false;
        }
        return true;
    }
   void solve(vector<vector<string>> &ans,vector<string> pld,string s,int i,int n){
       if(i>=n){
           ans.push_back(pld);
           return;
       }
        string sp;
       for(int j=i;j<n;j++){
           sp.push_back(s[j]);
           if(isPalindrome(sp)){
               pld.push_back(sp);
               solve(ans,pld,s,j+1,n);
               pld.pop_back();
           }
       }
   }
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>> ans;
        vector<string> pld;
        int i=0;
        solve(ans,pld,s,i,n);
        return ans;
    }
};