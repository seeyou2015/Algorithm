class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(256, -1);
        int start=0, end=0;
        int maxLen=0;
        for(end=0; end<s.length(); end++){
            if(index[s[end]]>=start){
                //maxLen=max(maxLen, end-start);
                start=index[s[end]]+1;
                index[s[end]]= end;
            }
            else{
                index[s[end]]=end;
                maxLen=max(maxLen, end-start+1);
            }
        }
        return maxLen;
    }
};
