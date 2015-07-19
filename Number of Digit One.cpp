//calculate the One digit on units' digit and tenths' digit and so on.
class Solution {
public:
    int countDigitOne(int n) {
        int e=0;
        int res=0;
        int cur=n;
        while(cur>0){
            int remainder = cur%10;
            if(remainder>1)
                res+=(cur/10+1)*pow(10,e);
            else if(remainder ==1)
                res+=(cur/10)*pow(10,e) +1 +n%(int)(pow(10,e));
            else
                res+=(cur/10)*pow(10,e);
            cur=cur/10;
            e++;
        }
        return res;
    }
};
