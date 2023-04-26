//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
        if(n>m) return 0;
        
        if(seats[0] == 0 && seats[1] == 0)
        {
            seats[0] = 1;
            n--;
        }
        
        if(seats[m-1] == 0 && seats[m-2] == 0)
        {
            seats[m-1] = 1;
            n--;
        }
        
        for(int i=1;i<m-1;i++){
            if(seats[i-1] == 0 && seats[i] == 0 && seats[i+1] == 0){
                seats[i] = 1;
                n--;
            }
        }
        
        return n<=0;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends