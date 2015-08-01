class Solution {
public:
    int getkth(vector<int>& nums1, int l1, int r1,vector<int>& nums2,int l2, int r2,int k){
        int m=r1-l1+1;
        int n=r2-l2+1;
        if(m>n) return getkth(nums2, l2, r2, nums1,l1, r1,k);
        if(m==0)
            return nums2[l2+k-1];
        if(k==1)
            return min(nums1[l1],nums2[l2]);
        int i=min((m+1)/2,k/2);
		int j=k-i;
        if(nums1[l1+i-1] < nums2[l2+j-1])
            return getkth(nums1,l1+i,r1,nums2,l2,r2,k-i);
        else
            return getkth(nums1,l1,r1,nums2,l2+j,r2,k-j);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m==0 && n==0)    return 0;
        int k=(m+n+1)/2;
        if((m+n)%2==0){
            return (getkth(nums1,0,m-1,nums2,0,n-1,k) + getkth(nums1,0,m-1,nums2,0,n-1,k+1))/2.0;
        }
        else
            return getkth(nums1,0,m-1,nums2,0,n-1,k);
    }
};
