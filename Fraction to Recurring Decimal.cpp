//overflow 30/35 test passed.
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if((numerator<0 && denominator>0) || (numerator>0 && denominator<0))
            res=res+"-";
        long long num=abs(numerator);
        long long den= abs(denominator);
        long long x=num/den;
        long long remainder=num%den;
        char str[255];
        sprintf(str, "%lld", x);
        res=res+str;
        if(remainder==0)
            return res;
        
        long long pos=0;
        res+=".";
        map<long long, long long> M;
        M.insert(pair<long long,long long>(remainder,pos++));
        string dec;
        while(remainder!=0){
            remainder=remainder*10;
            x=remainder/den;
            dec+=int2str(x);
            remainder=remainder%den;
            if(remainder==0)
                break;
            if(M.find(remainder)!=M.end()){
                string repeat= "("+dec.substr(M[remainder])+")";
                dec=dec.substr(0,M[remainder])+repeat;
                break;
            }
            else{
                M.insert(pair<long long,long long>(remainder,pos++));
                //dec=dec+char('0'+x);
            }
        }
        return res+dec;
    }
    string int2str(long long num) {
        string str;
        while (num) {
            int digit = num % 10;
            str += digit + '0';
            num /= 10; 
        } 
        if (str.empty()) return "0";
        reverse(str.begin(), str.end());
        return str; 
    }
};

//Solution:  O(N)
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0"; 
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-';
        long long numer = numerator < 0 ? (long long)numerator * (-1) : (long long)numerator;
        long long denom = denominator < 0 ? (long long)denominator * (-1) : (long long)denominator;
        long long integral = numer / denom;
        res += int2str(integral);
        long long rmd = numer%denom;
        if (!rmd) return res; 
        res += '.';
        rmd *= 10;
        unordered_map<long long, long long> mp;
        while (rmd) {
            long long quotient = rmd / denom;
            if (mp.find(rmd) != mp.end()) {
                res.insert(mp[rmd], 1, '(');
                res += ')';
                break;
            }
            mp[rmd] = res.size();
            res += int2str(quotient);
            rmd = (rmd % denom) * 10;
        }
        return res; 
    }
private:
    string int2str(long long num) {
        string str;
        while (num) {
            int digit = num % 10;
            str += digit + '0';
            num /= 10; 
        } 
        if (str.empty()) return "0";
        reverse(str.begin(), str.end());
        return str; 
    }
};
