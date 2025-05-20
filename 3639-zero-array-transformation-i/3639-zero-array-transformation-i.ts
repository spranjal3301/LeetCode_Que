function isZeroArray(nums: number[], queries: number[][]): boolean {
    const n = nums.length;
    const diff = Array(n+1).fill(0);

    for(const [s,e] of queries){
        diff[s]+=1;
        diff[e+1]-=1;
    }

    for(let i=0;i<n;i++){
        diff[i+1]+=diff[i];

        const chk = Math.max(nums[i]-diff[i],0);
        // console.log(nums[i]-diff[i]);
        // console.log(i);

        if(chk)return false;
    }

    // console.log(diff);

    return true;
};