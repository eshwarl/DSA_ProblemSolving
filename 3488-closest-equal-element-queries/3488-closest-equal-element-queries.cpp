class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for(int q : queries) {
            int val = nums[q];
            auto &vec = mp[val];
            
            if(vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            // Find position of q in vec
            auto it = lower_bound(vec.begin(), vec.end(), q);
            int idx = it - vec.begin();
            
            int res = INT_MAX;
            
            // Next occurrence (circular)
            int next = vec[(idx + 1) % vec.size()];
            int d1 = abs(next - q);
            res = min(res, min(d1, n - d1));
            
            // Previous occurrence (circular)
            int prev = vec[(idx - 1 + vec.size()) % vec.size()];
            int d2 = abs(prev - q);
            res = min(res, min(d2, n - d2));
            
            ans.push_back(res);
        }
        
        return ans;
    }
};