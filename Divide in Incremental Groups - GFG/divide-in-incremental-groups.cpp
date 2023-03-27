//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    map<string,int> mp;
    int dp[105][105][105];
    int mx=0;
    
    int func(int n,int k,int prev){
        if (k==0 && n==0){
            return 1;
        }
        else if (k==0 || n==0){
            return 0;
        }
        
        
        if (dp[n][k][prev]!=-1){
            return dp[n][k][prev];
        }
        
        int ans=0;
        
        for (int i=prev; i<=n; i++){
            ans+=func(n-i,k-1,i);
        }
     
       
     return dp[n][k][prev]=ans;
    }
    
    int countWaystoDivide(int n, int k) {
        // Code here
        memset(dp,-1,sizeof(dp));
      return  func(n,k,1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends