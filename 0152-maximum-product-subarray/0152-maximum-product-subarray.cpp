class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1;
        int sufix=1;
        int ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(prefix==0)prefix=1;
            if(sufix==0)sufix=1;
            prefix=prefix*nums[i];
            sufix=sufix*nums[n-i-1];
            ans=max(ans,max(prefix,sufix));
        }
        return ans;
    }
};