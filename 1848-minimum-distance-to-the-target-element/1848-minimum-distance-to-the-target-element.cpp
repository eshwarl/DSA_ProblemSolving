class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        if(nums.size()==1){
            return 0;
        }
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                ans=min(ans,abs(i-start));
            }
        }
        return ans;

    }
};