class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();

        vector<int> dp(n + 2, 0);        
        vector<int> count(n + 1, 0);     
        int answer = -1;

        for (int step = 0; step < n; step++) {
            int pos = arr[step];

            int left = dp[pos - 1];
            int right = dp[pos + 1];

            int newLen = left + right + 1;

            
            if (left > 0) count[left]--;
            if (right > 0) count[right]--;

            
            count[newLen]++;

         
            dp[pos - left] = newLen;
            dp[pos + right] = newLen;

            if (count[m] > 0) {
                answer = step + 1;
            }
        }
        return answer;
    }
};
