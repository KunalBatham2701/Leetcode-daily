//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
        int maxLength = a + b + c;

    // Find the maximum count of any one character
    int maxCount = max(a, max(b, c));

    // Calculate the remaining count of characters
    int remainingCount = maxLength - maxCount;

    // Check whether it is possible to form the required string
    if (maxCount > remainingCount * 2 + 2) {
        // If it is impossible, return -1
        return -1;
    } else {
        // Otherwise, return the maximum length of the string
        return a + b + c;
    }
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends