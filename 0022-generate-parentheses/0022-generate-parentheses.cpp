class Solution {
    void solve(vector<string>& ans,string str,int o,int c){
        if(c==0 and o==0){
            ans.push_back(str);
            return;
        }
        if(c<o){
            return;
        }
        if(o!=0){
            str.push_back('(');
            solve(ans,str,o-1,c);
            str.pop_back();
        }
        if(c!=0){
            str.push_back(')');
            solve(ans,str,o,c-1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str="(";
        int o=n-1;
        int c=n;
        solve(ans,str,o,c);
        return ans;
    }
};