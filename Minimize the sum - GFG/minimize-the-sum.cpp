//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
       int sum=0;
        multiset<int>st;
        for(auto i:arr){
            st.insert(i);
        }
        while(!st.empty()){
            if(st.size()==1)break;
            int a=*st.begin();
            st.erase(st.begin());
            int b=*st.begin();
            st.erase(st.begin());
            sum+=(a+b);
            st.insert(a+b);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends