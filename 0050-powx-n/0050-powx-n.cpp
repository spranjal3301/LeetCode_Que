class Solution {
private:
    double fastPow(double x, long long n){
        double ans=1.00000;
        while(n>0){
            if(n&1)ans*=x;
            x=x*x;
            n=n>>1;
        }
        return ans;
    }
public:
    double myPow(double x, int n) {
        
       long long ln=n;
        if(n<0){
            return (double)1/fastPow(x,-ln);
        }
        else{
            return fastPow(x,ln);
        }
        return 1.00000;
   
      
    }
};