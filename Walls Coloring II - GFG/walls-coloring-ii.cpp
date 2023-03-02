//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n=costs.size();
        int k=costs[0].size();
        if(n==1 && k==1){
            return costs[0][0];
        }
        if(k==1){
            return -1;
        }
        int mn=INT_MAX,sec_mn=INT_MAX,idx=0;
        vector<vector<int>> dp(n,vector<int>(k));
        for(int j=0;j<k;j++){
            dp[0][j]=costs[0][j];
            if(dp[0][j]<=mn){
                sec_mn=mn;
                mn=dp[0][j];
                idx=j;
            }
            else if(dp[0][j]<sec_mn && dp[0][j]!=mn){
                sec_mn=dp[0][j];
            }
        }
        for(int i=1;i<n;i++){
            int new_min=INT_MAX,new_sec_min=INT_MAX,new_idx=0;
            for(int j=0;j<k;j++){
                if(j!=idx){
                    dp[i][j]=costs[i][j]+mn;
                }
                else{
                    dp[i][j]=costs[i][j]+sec_mn;
                }
                if(dp[i][j]<=new_min){
                    new_sec_min=new_min;
                    new_min=dp[i][j];
                    new_idx=j;
                }
                else if(dp[i][j]<new_sec_min && dp[i][j]!=new_min){
                    new_sec_min=dp[i][j];
                }
            }
            mn=new_min;
            sec_mn=new_sec_min;
            idx=new_idx;
        }
        
        return mn;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends