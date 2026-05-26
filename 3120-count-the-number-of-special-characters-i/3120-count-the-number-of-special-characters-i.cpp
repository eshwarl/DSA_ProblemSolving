class Solution {
public:
    int numberOfSpecialChars(string word) {

        int count = 0;

   
        for(char ch = 'a'; ch <= 'z'; ch++) {

            bool lower = false;
            bool upper = false;

            for(int i = 0; i < word.size(); i++) {

                if(word[i] == ch)
                    lower = true;

                if(word[i] == ch - 32)
                    upper = true;
            }

           
            if(lower && upper)
                count++;
        }

        return count;


        
    }
};