class Solution {
public:
    char findTheDifference(string s, string t) {
        int s1=0;
        int t1=0;

        int n=s.size();
        for(int i=0;i<n;i++){
            s1+=s[i];
            t1+=t[i];
        }
        t1+=t[n];

        return t1-s1;

    }
};