//Use two pointers and sliding window.
// O(N)
class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length(), n=t.length();
        if(m<n) return "";
        vector<int> need(256, 0);   
        vector<int> has(256,0);
        for(int i=0; i<n;i++)
            need[t[i]]++;
        
        int start=0, end= 0;
        int count=0;
        int minLen=INT_MAX, minStart=0;
        for(; end< m; end++){
            if(need[s[end]] ==0 )   continue;
            if(has[s[end]]< need[s[end]])
                count++;
            has[s[end]] ++;
            if(count == n){
                while(start <= end){
                    if(need[s[start]] ==0)
                        start++;
                    else if(has[s[start]] > need[s[start]]){
                        has[s[start]]--;
                        start++;
                    }
                    else
                        break;
                }
                if(minLen > end-start+1){
                    minLen= end-start +1;
                    minStart = start;
                }
            }
        }
        if(minLen ==INT_MAX)    return "";
        return s.substr(minStart, minLen);
    }
};
