//Simple DP    O(n)
class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0)    return 0;
        int dp[n+1];
        dp[0]=1;
        dp[1]= (s[0]!='0');
        for(int i=2;i<=n;i++){
            
            if(s[i-1]>='0'&&s[i-1]<='6'&&s[i-2]=='2'  || s[i-2]=='1')
            {
                if(s[i-1]=='0')
                    dp[i]=dp[i-2];
                else
                    dp[i]=dp[i-1]+dp[i-2];
            }
            else if(s[i-1]!='0')
            {
                dp[i]=dp[i-1]; 
            }
            else
                dp[i]=0;
        }
        return dp[n];
        
    }
};
