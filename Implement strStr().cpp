//O(M*N)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        for(int i=0; i<m-n+1 ;i++){
            int j=0;
            for(;j<n;j++)
                if(needle[j] != haystack[i+j])
                    break;
            if(j==n)
                return i;
        }
        return -1;
    }
};
