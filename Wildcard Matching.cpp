//'asterisk' is the index of the *,'match' is the index that the asterisck match to
class Solution { 
public:
    bool isMatch(string s, string p) {
        int m=s.length(), n=p.length();
        if(n==0) return m==0;
        int match=0, asterisk=-1;
        int i=0, j=0;
        while(i<m){
            if(j<n && (s[i]==p[j] || '?'==p[j]))
                i++, j++;
            else if(j<n && '*'==p[j]){
                asterisk=j++;
                match=i;
            }
            else if(asterisk>=0){
                i=++match;
                j=asterisk+1;
            }
            else
                return 0;
        }
        while(j<n &&'*'==p[j]) j++;
        return j==n;
    }
};
