//If the next number is larger than the current one, res-=num, else res+=num.
class Solution {
public:
    int romanToInt(string s) {
        if(s.length()==0)
            return 0;
        int map[26];
        map['I'-'A'] = 1; map['V'-'A'] = 5; map['X'-'A'] = 10; map['L'-'A'] = 50;
        map['C'-'A'] = 100; map['D'-'A'] = 500; map['M'-'A'] = 1000;
        int res = 0, n = s.size();
        res+=map[s[n-1]-'A'];
        for(int i = 0; i < n-1; i++)
        {
            if(map[s[i]-'A'] >= map[s[i+1]-'A'])
                res += map[s[i]-'A'];
            else res -= map[s[i]-'A'];
            
        }
        return res;
    }
};
