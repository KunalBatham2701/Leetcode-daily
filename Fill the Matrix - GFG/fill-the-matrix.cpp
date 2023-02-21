//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        x--;y--;
        N--; M--;
        int ul = x + y;
        int lr = (N-x) + (M-y);
        int ur = x + (M-y);
        int ll = (N-x) + y;
        
        //suppos ul is max
        int max = ul;
        if(lr>max) max = lr;
        if(ur>max) max = ur;
        if(ll>max) max = ll;
            
        return max;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends