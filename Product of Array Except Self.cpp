//Time O(n) Space(O(1))
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()<1)
            return nums;
        vector<int> res;
        if(nums.size()==1){
            res.push_back(0);
            return res;
        }
        int NumberOf0=0;
        long long productOfAll=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)
                NumberOf0++;
            else
                productOfAll=productOfAll*nums[i];
        }
        for(int i=0; i<nums.size(); i++){
            if(NumberOf0>1)
                res.push_back(0);
            else if(NumberOf0 ==1){
                if(nums[i] ==0)
                    res.push_back(productOfAll);
                else
                    res.push_back(0);
            }
            else
                res.push_back(productOfAll/nums[i]);
        }
        return res;
    }
};
