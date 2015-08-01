//Two Pass
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)    return 0;
        int Max=0,MaxIndex=-1;
        for(int i=0; i<height.size(); i++)
            if(height[i]>Max){
                Max=height[i];
                MaxIndex=i;
            }
        
        int max1=height[0];
        int water=0;
        for(int i=1; i<MaxIndex; i++){
            if(height[i]<max1)
                water+=max1-height[i];
            else
                max1=height[i];
        }
        int max2=height[height.size()-1];
        for(int i=height.size()-2; i>MaxIndex; i--){
            if(height[i]<max2)
                water+=max2-height[i];
            else
                max2=height[i];
        }
        return water;
        
    }
};

//One Pass
class Solution {
public:
    int trap(vector<int> &A) {
        int n=A.size();
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};
