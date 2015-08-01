//Recursive
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length()==0) 
        {  
            return s.length()==0;  
        }  
        if (p.length()>1 && p[1]=='*') 
            {  
                string tmp=p.substr(2);
                int i=0;
                while (i<s.length() && (s[i] == p[0] || p[0] == '.')) 
                {  
                    if (isMatch(s.substr(i++), tmp))
                    {  
                        return true;  
                    }  
                }  
                return isMatch(s.substr(i), tmp);  
            }  
            else 
            {  
                if ( s.length()>0 && (s[0] == p[0] || p[0] == '.')) 
                {  
                    return isMatch(s.substr(1),p.substr(1));
                }  
            }  
        
        return false; 
    }
};

//DP
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length(), n=p.length();
        if(n==0)    return m==0;
        vector<bool> row(n+1,0);
        vector<vector<bool>> dp(m+1,row);
        dp[0][0]=1;
        for(int i=1; i<=n; i++){
            dp[0][i]= i>1&&'*'==p[i-1]&&dp[0][i-2];
        }
        for(int i=1;i<=m; i++)
            dp[i][0]=0;
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++){
                if(p[j-1]!='*')
                    dp[i][j]=dp[i-1][j-1] && (s[i-1]==p[j-1] || '.'==p[j-1]);
                else
                    dp[i][j]=dp[i][j-2]|| (s[i-1]==p[j-2]||'.'==p[j-2])&&dp[i-1][j];
            }
        return dp[m][n];
    }
};
