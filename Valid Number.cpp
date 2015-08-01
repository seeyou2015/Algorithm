class Solution {
public:
    void deleteParenthese(string &s){
        int begin=0,end=s.length()-1;
        for(int i=0 ;i<s.length(); i++){
            if(s[i] == ' ')
                begin++;
            else
                break;
        }
        for(int i=end ;i>=0; i--){
            if(s[i] == ' ')
                end--;
            else
                break;
        }
        if(end<begin)
            s= "";
        else
            s=s.substr(begin, end-begin+1);
    }
    bool isNumber(string s) {
        deleteParenthese(s);
        if (s.length() == 0) return false;
        bool hasE = false;
        bool hasDot = false;
        bool hasNumber = false;
        
        for (int i = 0; i < s.length(); i++) {
            // e cannot be the first character
            if (i == 0 && s[i] == 'e') 
				return false;
            if (s[i] == 'e') {
                // e cannot be replicated nor placed before number
                if (hasE == true || hasNumber == false) {
                    return false;
                } else {
                	hasE = true;
                }
            } 
            
            if (s[i] == '.') {
                // '.' cannot be replicated nor placed after 'e'
            	if (hasDot == true || hasE == true) {
                	return false;
                } else {
                	hasDot = true;
                }
            }
            // the sign can be placed at the beginning or after 'e'
            if (i != 0 && s[i - 1] != 'e' && (s[i] == '+' || s[i] == '-')) 
				return false;
            
            // no other chacraters except '+', '-', '.', and 'e'
            if ((s[i] > '9' || s[i] < '0') && s[i] != '+' && s[i] != '-' && s[i]!= '.' && s[i] != 'e')
				return false;  
            
            // check whether numbers are included.
            if (s[i] <= '9' && s[i] >= '0') {
                hasNumber = true;
            }
        }
        // '+', '-', and 'e' cannot be the last character
        if (s[s.length() - 1] == '-' || s[s.length() - 1] == '+' || s[s.length() - 1] == 'e') 
			return false;

        return hasNumber;
    }
};
