//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    char c=str[0];
    int res=0;
    for(int i=1;i<str.size();i++){
        if(str[i]!=c and str[i-1]==c) res++;
    }
    
    return res+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends