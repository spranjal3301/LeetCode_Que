class Solution {
public:
     string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int count1=0;

        int i=0;
        while(i<n && s[i]!='1')i++;
    
        int j=i;
        while (i<n && count1!=k)
        {
            if(s[i]=='1')count1++;
            i++;
        }
         
        if(count1!=k)return"";
        int a=i-1;
        int b=j;
        j++;
        while (i<n and j<n)
        {  
            while (i<n && count1!=k+1)
            {
                if(s[i]=='1')count1++;
                i++;
            }
            while(j<n &&j<=i && count1!=k){
                if(s[j]=='1')count1--;
                j++;
            } 
          

            if((i-j)<(a-b) && count1==k){
                a=i-1;
                b=j-1;
            }
            else if((i-j)==(a-b) && count1==k){
                string s1=s.substr(b,a-b+1);
                string s2=s.substr(j-1,i-j+1);
                if(s2<s1){
                    a=i-1;
                    b=j-1;
                }
            } 
        }
            
    
        return s.substr(b,a-b+1);

    }
};