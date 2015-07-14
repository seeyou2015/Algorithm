//Binary search. 
//Because it can contain duplicates, when low==mid, low++. So the worst case is O(n) 
public class Solution {
    public int findMin(int[] nums) {
        int len=nums.length;
        int min=Integer.MAX_VALUE;
        int low=0,high=len-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[low]){
                min=Math.min(min, nums[low]);
                low=mid+1;
            }
            else if(nums[mid]<nums[low]){
                min=Math.min(min, nums[mid]);
                high=mid-1;
            }
            else{
                min=Math.min(min, nums[low++]);
            }
        }
        return min;
    }
}
