class Solution {
public:
    bool isSubsequence(string s, string t) {
       int n=s.size(); 
       int m=t.size();
       int i=0,j=0; 
      
       while(i<n and j<m){
           if(s[i]==t[j])i++;
           j++;
       } 

       if(i==n)return true;
       return false;
    }
};