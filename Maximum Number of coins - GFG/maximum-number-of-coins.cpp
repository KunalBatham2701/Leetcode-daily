//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
       int maxCoins(int n, vector <int> &a)

        {

            vector<vector<int>> dp(n,vector<int> (n,0));

            

            for(int gap=0;gap<n;gap++)

            {

                for(int i=0,j=gap;j<n;j++,i++)

                {

                    if(gap==0)

                    {

                        int me=a[i];

                        if(i-1>=0)

                            me*=a[i-1];

                        if(i+1<n)

                            me*=a[i+1];

                        dp[i][j]=me;

                    }

                    else

                    {

                        int maxi=INT_MIN;

                        for(int k=i;k<=j;k++)

                        {

                            int pre=0;

                            if(k!=i)

                                pre=dp[i][k-1];

                            int post=0;

                            if(k!=j)

                                post=dp[k+1][j];

                            int me=a[k];

                            if(i-1>=0)

                                me*=a[i-1];

                            if(j+1<n)

                                me*=a[j+1];

                            

                            int now=me+pre+post;

                            maxi=max(maxi,now);

                        }

                        dp[i][j]=maxi;

                    }

                }

            }

            return dp[0][n-1];

        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends