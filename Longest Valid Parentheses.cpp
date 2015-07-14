//Solution 1: 
//Use a stack to track the postion of the unmatched parentheses. 
//When parentheses match, i-stack.top() is the length.
//Time complexilty: O(n)     Space: O(n)
class Solution {
public:
       int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxL=0;
        for(int i=0;i<s.size();i++)
        {
            int t=stk.top();
            if(t!=-1&&s[i]==')'&&s[t]=='(')
            {
                stk.pop();
                maxL=max(maxL,i-stk.top());
            }
            else
                stk.push(i);
        }
        return maxL;
    }
};

//Solution 2: 
// Two passes: First scan from left to rigth, then scan from right to left. When there is a unbalanced parenthese, reset the start point.
// Time complexilty: O(n)     Space: O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int answer = 0, depth = 0, start = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++depth;
            } else {
                --depth;
                if (depth < 0) {
                    start = i;
                    depth = 0;
                } else if (depth == 0) {
                    answer = max(answer, i - start);
                }
            } 
        }

        depth = 0;
        start = s.size();
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++depth;
            } else {
                --depth;
                if (depth < 0) {
                    start = i;
                    depth = 0;
                } else if (depth == 0) {
                    answer = max(answer, start - i);
                }
            } 
        }
        return answer;
    }
};
//Solution 3: DP   Time: O(n)  Space:O(n)
//1. dp[i] = {max(k) | s[i-k+1, i] is well formed. k=0 means empty}
//2. For char s[i], we should check the char s[i-1-dp[i-1]]. 
//If s[i] and s[i-1-dp[i-1]] are matched, substring from  i-1-dp[i-1] to i is well formed. 
//Then, we should joint it with previous well formed substring which ends at s[i-1-dp[i-1]-1].

		int longestValidParentheses(string s) {
				vector<int> dp(s.length(),0);
				int res = 0;
        for(int i=1; i<s.length(); ++i)
         		if(s[i]==')' && i-1-dp[i-1]>=0 &&s[i-1-dp[i-1]]=='('){ 
						//i-1-dp[i-1] is the index of the last un matched parenthese
            		if(i-1-dp[i-1]-1 >= 0) 
										dp[i]= dp[i-1]+2+dp[i-1-dp[i-1]-1];
            		else  
										dp[i]= dp[i-1]+2;
                res = max(res, dp[i]);
                }
        return res;
        }



//Solution 4:
//Use a array(sign), mark all the matched parentheses position to 1. Then count the consecutive 1s.
class Solution {
public:
int longestValidParentheses(const string s) {
        vector<char> stack;
        int n=s.length();
        vector<int> sign(n,0);
        vector <int> index;
        for(int i=0; i<n; i++)
        {
            if(stack.size()==0)
            {
                stack.push_back(s[i]);
                if(s[i]=='(')
                    index.push_back(i);
            }
            else if(s[i]==')' && stack.back()=='(')
            {
                stack.pop_back();
                sign[i]=1;
                sign[index.back()]=1;
                index.pop_back();
                
            }
            else if(s[i]=='(')
            {
                stack.push_back(s[i]);
                index.push_back(i);
            }
            else 
                stack.push_back(s[i]);
        }
        int max=0;
        int tmp=0;
        for(int i=0; i<n; i++)
        {
            if(sign[i]==1)
                tmp++;
            else
                tmp=0;
            max= std::max(max,tmp);
        }
        return max;
    }
};
