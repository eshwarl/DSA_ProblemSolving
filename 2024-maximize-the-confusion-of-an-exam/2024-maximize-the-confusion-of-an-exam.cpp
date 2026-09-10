class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 0;
        int t = 0, f = 0;
        int ans = 0;

        for (int r = 0; r < answerKey.size(); r++) {

            if (answerKey[r] == 'T')
                t++;
            else
                f++;

          
            while (min(t, f) > k) {

                if (answerKey[l] == 'T')
                    t--;
                else
                    f--;

                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};