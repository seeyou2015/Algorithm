// Two pointers
// O(N^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)
            return res;
        sort(nums.begin(), nums.end());
        
        for(int k=0; k<nums.size()-2;k++){
            if(k>0 &&nums[k]==nums[k-1])
                continue;
            int target = -nums[k];
            int i=k+1;
    		int j=nums.size()-1;
    		while(i<j)
    		{
    			if(nums[i]+nums[j]<target){
    				i++;
    				while(nums[i]==nums[i-1])
    			        i++;
    			}
    			else if(nums[i]+nums[j]>target){
    				j--;
    				while(nums[j]==nums[j+1])
    			        j--;
    			}
    			else{
    			    vector<int> tmp;
    			    tmp.push_back(nums[k]);
    			    tmp.push_back(nums[i]);
    			    tmp.push_back(nums[j]);
    			    res.push_back(tmp);
    			    while(nums[i]==nums[i+1])
    			        i++;
    			    i++;
    			}
    			
    		}
        }
        return res;
    }
};
