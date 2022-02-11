// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
        The number of unique paths is the sum of the number of unique paths from the tile to the right of starting 
        point + the number of unique paths from the tile that is at the bottom of the starting 
        
        Overlapping Substructure: We break this into smaller unique subproblems as in for the starting tile, this solution to 
        this problem depends on a subproblem where we have to find the number of unique 
        
        We cache the 
        m = m - 1
        n = n - 1 
        
        Where j and i are zero  
        i, j+1, i+1,  j
       
    
        if i == m-1 and j == n - 1:
            dp[i][j] = 1;
            return dp[i][j];
        if (i and j are invalid):
            return 0    
        otherwise if (dp[i][j] != 0):
            return dp[i][j]   
        otherwise:
            to the right                   and down 
            dp[i][j] = numuniquepaths(dp, i, j + 1) + numuniquepaths(dp, i + 1, j)
        return dp[i][j]
        */
        
        
        
        /*
        //Recursive Appraoch
//This will give a TLE
  int solve(int i,int j,int m,int n)
    {
        if(i>=m||j>=n)
            return 0;
        if(i==m-1&&j==n-1)
            return 1;
        return solve(i+1,j,m,n)+solve(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
    }

//DP(recursive+memoization)
    int solve(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i>=m||j>=n)
            return 0;
        if(i==m-1&&j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
      vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
//TC:O(m*n)
//SC:O(m*n)

//DP(Bottom-Up Appraoch)
  int uniquePaths(int m, int n) {
     int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
        
        
        */
        vector<vector<int>> dp(m, vector<int> (n, 0));
        int result = numuniquepaths(dp, m, n, 0, 0);
        return result;
    }
    
    
    int numuniquepaths(vector<vector<int>>& dp, int m, int n, int i, int j) {
        if (i >= m or j > n - 1) {
            return 0;
        }
        if (i == m - 1 and j == n - 1) {
            dp[i][j] = 1;
            return dp[i][j];
        }
      
         if (dp[i][j] != 0) {
            return dp[i][j];
        } else {
            dp[i][j] = numuniquepaths(dp, m, n, i, j + 1) + numuniquepaths(dp, m, n, i + 1, j);
        }
        return dp[i][j];
        
    }
};