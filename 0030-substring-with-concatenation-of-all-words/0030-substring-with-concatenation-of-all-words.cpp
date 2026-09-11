class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;
        int len = words[0].size();
        int n = words.size();

        unordered_map<string, int> mp;

        for (auto &w : words)
            mp[w]++;

        for (int offset = 0; offset < len; offset++) {

            int l = offset, r = offset, cnt = 0;
            unordered_map<string, int> seen;

            while (r + len <= s.size()) {

                string w = s.substr(r, len);
                r += len;

                if (mp[w] == 0) {
                    seen.clear();
                    cnt = 0;
                    l = r;
                }
                else {
                    seen[w]++;
                    cnt++;

                    while (seen[w] > mp[w]) {
                        string x = s.substr(l, len);
                        seen[x]--;
                        l += len;
                        cnt--;
                    }

                    if (cnt == n) {
                        ans.push_back(l);

                        string x = s.substr(l, len);
                        seen[x]--;
                        l += len;
                        cnt--;
                    }
                }
            }
        }

        return ans;
    }
};