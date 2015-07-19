//Solution 1:
// Time O(N^2)  Space O(m+n)
class Solution {
public:
        void setZeroes(vector<vector<int> > &matrix) {
        vector<int> x;
        vector<int> y;
        int m=matrix[0].size();
        int n=matrix.size();
        for(int j=0;j<n;j++)
		{
            for(int i =0;i<m;i++)
                if(matrix[j][i]==0)
                {
                    x.push_back(i);
                    y.push_back(j);
                    //matrix[j][0]=0;
                    //matrix[0][i]=0;
                }
		}
		for(int i=0; i<x.size();i++)
		{
		    for(int j=0;j<n;j++)
                matrix[j][x[i]]=0;
		}
		for(int j=0; j<y.size();j++)
		{
		    for(int i =0;i<m;i++)
                matrix[y[j]][i]=0;
		}    
        
        
    }
};

//Solution 2: find the last row which has 0, and use it to store the 0-collumns
//Time O(N^2) Space O(1)

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {

        int H = matrix.size();
        int W = matrix[0].size();

        // find the last 0 row
        int last_0_row = -1;
        for (int y = H - 1; y >= 0 && last_0_row == -1; y--)
            for (int x = 0; x < W; x++)
                if (matrix[y][x] == 0)
                {
                    last_0_row = y;
                    break;
                }
        if (last_0_row == -1)
            return;

        // go row by row
        for (int y = 0; y < last_0_row; y++)
        {
            bool this_is_a_0_row = false;

            for (int x = 0; x < W; x++)
            {
                if (matrix[y][x] == 0)
                {
                    this_is_a_0_row = true;
                    matrix[last_0_row][x] = 0;
                }
            }

            if (this_is_a_0_row)
            for (int x = 0; x < W; x++)
            {
                matrix[y][x] = 0;
            }
        }

        // set collums to 0
        for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
        {
            if (matrix[last_0_row][x] == 0)
                matrix[y][x] = 0;
        }

        // set the last 0 row 
        for (int x = 0; x < W; x++)
        {
            matrix[last_0_row][x] = 0;
        }
    }
};
