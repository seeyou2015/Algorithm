//Scan from left to right, move the 0 to left and move 2 to right.
class Solution {
public:
    void sortColors(vector<int>& nums) {
       if(nums.size()<2) return;
       int low=0,high=nums.size()-1;
       int i=0;
       while(i<=high){
           if(nums[i]==0){
               swap(nums[i],nums[low]);
               low++,i++;
           }
           else if(nums[i]==2){
               swap(nums[i],nums[high]);
               high--;
           }
           else
               i++;
       }
       return;
   }
};
