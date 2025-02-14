class ProductOfNumbers {
    vector<int> nums;
    int cnt ;
public:
    ProductOfNumbers() {
       cnt = -1;
       nums.push_back(1); 
    }
    
    void add(int num) {
        if(num == 0){
            nums.push_back(1);
            cnt = nums.size();
        }
        else nums.push_back(nums.back()*num);
    }
    
    int getProduct(int k) {
        // cout<<nums.back()<<" ";
        if(cnt!=-1){
            if(nums.size()-cnt>=k){
                return (nums.back())/nums[nums.size()-k-1];
            }else{
                cout<<nums.size()-cnt<<" "<<k<<endl; 
                 return 0;}
        }

        return (nums.back())/nums[nums.size()-k-1]; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
//  0 1 2 3 4  5
//  3 0 2 5 4
//  1 3 1 2 10 40 

    // 3

//  3 , 0 , 0 0 0 