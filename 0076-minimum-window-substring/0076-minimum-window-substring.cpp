class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};

        int l = 0, r = 0;
        int minlen = INT_MAX;
        int sindex = -1;
        int cnt = 0;

        int n = s.size();
        int m = t.size();

        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while (r < n) {

          
            if (hash[s[r]] > 0) {
                cnt++;
            }

            hash[s[r]]--;
            r++;

           
            while (cnt == m) {

              
                if (r - l < minlen) {
                    minlen = r - l;
                    sindex = l;
                }

              
                hash[s[l]]++;

                if (hash[s[l]] > 0) {
                    cnt--;
                }

                l++;
            }
        }

        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};