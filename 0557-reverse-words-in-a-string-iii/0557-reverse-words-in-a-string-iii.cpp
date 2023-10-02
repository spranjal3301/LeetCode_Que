class Solution {
    void reverseRange(string& s,int start,int end){
    while(start<end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
}
public:
    string reverseWords(string& s) {
        if(s.size()==1)return s;
        int start=0;
        int i=0;
        while(i<=s.size()){
            if(i==s.size() or s[i]==' '){
               reverseRange(s,start,i-1);
                start=i+1;
            }
            i++;
        }
        return s;

    }
};