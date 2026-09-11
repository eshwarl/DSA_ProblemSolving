class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;
        int len = words[0].size();
        int n = words.size();

        unordered_map<string, int> hash;

        for (auto &w : words)
            hash[w]++;

        for (int offset = 0; offset < len; offset++) {

            int l = offset, r = offset, cnt = 0;
            auto mp = hash;

            while (r + len <= s.size()) {

                string word = s.substr(r, len);
                r += len;

                if (mp.find(word) == mp.end()) {
                    mp = hash;
                    l = r;
                    cnt = 0;
                    continue;
                }

                mp[word]--;
                cnt++;

                while (mp[word] < 0) {
                    string left = s.substr(l, len);
                    mp[left]++;
                    l += len;
                    cnt--;
                }

                if (cnt == n) {
                    ans.push_back(l);

                    string left = s.substr(l, len);
                    mp[left]++;
                    l += len;
                    cnt--;
                }
            }
        }

        return ans;
    }
};