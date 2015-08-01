class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num(n,0);
		for(int i=0; i<n;i++)
			num[i]=i+1;
        vector<int> product(n+1,1);
        for(int i=2; i<=n; i++)
            product[i]=product[i-1]*(i-1);
        string res;
        k--;
        for(int i=n; i>1;i--){
            int quotient=k/product[i];
            k=k%product[i];
            res+='0'+quotient;
        }
        res+='0'+k;
		for(int i=0; i<res.length(); i++){
			int index=res[i]-'0';
			res[i]=num[index]+'0';
			num.erase(num.begin()+index);
		}
		return res;
    }
};
