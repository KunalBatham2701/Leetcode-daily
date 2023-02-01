//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        vector<long long int>ans(3, 0);
        vector<long long int>temp(3, 0);
        for(int ind = N-1; ind >= 0; ind--){
            temp[0] = r[ind] + min(ans[1], ans[2]);
            temp[1] = g[ind] + min(ans[0], ans[2]);
            temp[2] = b[ind] + min(ans[0], ans[1]);
            ans = temp;
        }
        
        return min(ans[0], min(ans[1], ans[2]));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends