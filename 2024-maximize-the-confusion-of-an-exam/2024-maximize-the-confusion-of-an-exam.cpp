class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l=0,r=0;
        int maxlen=0;
        int maxfreq=0;
        int hash[26]={0};
        while(r<answerKey.size()){
            hash[answerKey[r]-'A']++;
            maxfreq=max(maxfreq,hash[answerKey[r]-'A']);

            if((r-l+1)-maxfreq>k){
                hash[answerKey[l]-'A']--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;


        }
        return maxlen;
    }
};