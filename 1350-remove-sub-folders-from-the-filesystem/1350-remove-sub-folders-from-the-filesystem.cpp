class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> res;

        string prev = "0" ;
        for(auto f:folder){
            if(f.substr(0,prev.size())!=prev){
                res.push_back(f);
                prev = f;
            }else{
                int i = prev.size();
                if(i<f.size() && f[i]!='/'){
                    res.push_back(f);
                    prev = f;
                }
            }
        }
        return res;
    }
};