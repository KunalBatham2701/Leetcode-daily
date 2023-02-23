//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int mod=1e9+7;
  public:
    int uniquePaths(int r, int c, vector<vector<int>> &grid) {
        if(grid[0][0]==0 or grid[r-1][c-1]==0){
            return 0;
        }
        int dp[r][c];
        dp[0][0]=1;
        //fill the first row
        for(int p=1;p<c;p++){
            if(grid[0][p]==0){
                dp[0][p]=0;
            }else{
                dp[0][p]=dp[0][p-1];
            }
            
        }
        //fill the first col
        for(int p=1;p<r;p++){
            if(grid[p][0]==0){
                dp[p][0]=0;
            }else{
                dp[p][0]=dp[p-1][0];
            }
        }
        //fill the rest
        for(int a=1;a<r;a++){
            for(int b=1;b<c;b++){
                if(grid[a][b]==0){
                    dp[a][b]=0;
                }else{
                    dp[a][b]=(dp[a-1][b]%mod+dp[a][b-1]%mod)%mod;
                }
            }
        }
        return dp[r-1][c-1]%mod;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends