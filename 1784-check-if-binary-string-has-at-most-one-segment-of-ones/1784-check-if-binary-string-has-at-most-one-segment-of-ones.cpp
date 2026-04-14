class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.size()==1 && s[0]=='1')return true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0' && s[i+1]=='1')
                return false;
            
        }
        return true;
    }
    
};