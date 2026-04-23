class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n, 0);
        
        unordered_map<int, vector<int>> mp;
        
       
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
       
        for (auto &it : mp) {
            vector<int> &indices = it.second;
            int k = indices.size();
            
            vector<long long> prefix(k + 1, 0);
            
           
            for (int i = 0; i < k; i++) {
                prefix[i + 1] = prefix[i] + indices[i];
            }
            
           
            for (int i = 0; i < k; i++) {
                long long idx = indices[i];
                
                long long left = (long long)i * idx - prefix[i];
                long long right = (prefix[k] - prefix[i + 1]) - (long long)(k - i - 1) * idx;
                
                res[idx] = left + right;
            }
        }
        
        return res;
    }
};