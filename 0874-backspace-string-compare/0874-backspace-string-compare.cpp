class Solution {
 bool areStacksEqual(std::stack<char> stack1, std::stack<char> stack2) {
    if (stack1.size() != stack2.size()) {
        return false;
    }

    while (!stack1.empty()) {
        if (stack1.top() != stack2.top()) {
            return false;
        }
        stack1.pop();
        stack2.pop();
    }

    return true;
}
public:
    bool backspaceCompare(string s, string t) {
      stack<char> s1;  
      stack<char> t1;
      for(int i=0;i<s.size();i++){
         
          if(s[i]!='#'){
              s1.push(s[i]);
          
          }
          else if(!s1.empty() && s[i]=='#'){
              s1.pop();
          }
      }  

      for(int i=0;i<t.size();i++){
         
          if(t[i]=='#' ){
            if(t1.empty()){
              continue;
          }
             t1.pop();
          }
          else{
              t1.push(t[i]);
          }
      } 

      return areStacksEqual(s1,t1); 
    }
};