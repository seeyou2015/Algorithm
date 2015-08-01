//O(N^2)
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m=matrix.size();
        if(m==0 )
            return 0;
        int n=matrix[0].size();
        if(n==0)
            return 0;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        vector<int> height(n, 0);
        int maxA=0;
        for(int i=0; i<m; i++){
            int cur_left=0, cur_right=n-1; 
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    height[j]++;
                else{
                    height[j]=0;
                }
            }
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    left[j]=max(cur_left,left[j]);
                else{
                    left[j]=0;
                    cur_left=j+1;
                }
            }
            for(int j=n-1; j>=0; j--){
                if(matrix[i][j]=='1')
                    right[j]=min(cur_right,right[j]);
                else{
                    right[j]=n;
                    cur_right=j-1;
                }
            }
            for(int j=0; j<n; j++)
                maxA = max(maxA,(right[j]-left[j]+1)*height[j]);
        }
        return maxA;
    }
};
