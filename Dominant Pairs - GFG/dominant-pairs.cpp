//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        int dominantPairsCount = 0;
    
    // Sort the first half of the array in non-decreasing order
    sort(arr.begin(), arr.begin() + n/2);
    
    // Sort the second half of the array in non-increasing order
    sort(arr.begin() + n/2, arr.end());
    
    // Initialize two pointers, i and j, to the first element of their respective halves
    int i = 0, j = n/2;
    
    // Iterate over both halves of the array simultaneously using two pointers
    while (i < n/2 && j < n) {
        // Check if the current pair satisfies the condition for dominance
        if (arr[i] >= 5 * arr[j]) {
            /* If yes, increment the dominantPairsCount by the number of elements remaining 
            in the second half*/
            dominantPairsCount += n/2 - i;
            // Move to the next element in the second half
            j++;
        } else {
            // If no, move to the next element in the first half
            i++;
        }
    }
    
    // Return the count of dominant pairs
    return dominantPairsCount;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends