class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << endl;
            if(hashMap.find(target - nums[i]) != hashMap.end()){
                result.push_back(i);
                result.push_back(hashMap[target - nums[i]]);
                return result;
            }
            hashMap[nums[i]] = i;
        }
        return result;
    }
};