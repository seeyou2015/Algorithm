class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        int pivot=len-2;
        while(pivot>=0){
            if(nums[pivot]<nums[pivot+1]) break;
            pivot--;
        }
        if(pivot==-1)
            reverse(nums.begin(), nums.end());
        else{
            for(int i=len-1; i>pivot; i--){
                if(nums[i]>nums[pivot]){
                    swap(nums[i],nums[pivot]);
                    reverse(nums.begin()+pivot+1,nums.end());
                    break;
                }
            }
        }
    }
};
