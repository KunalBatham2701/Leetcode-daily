//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    long solve(vector<int>& A, int N, int M) {
        unordered_map<int, int> map;
        int cur = 0;
        long tot = 0, ans = 0;
        map[cur] = 1;

        for (int i = 0; i < N; i++) {
            int x;
            if (A[i] >= M)
                x = 1;
            else
                x = -1;

            if (x == -1)
                tot -= map[cur - 1];
            else
                tot += map[cur];

            cur += x;
            ans += tot;
            map[cur] = map[cur] + 1;
        }

        return ans;
    }

    long countSubarray(int N,vector<int>& A, int M) {
        long v1 = solve(A, N, M);
        long v2 = solve(A, N, M + 1);
        return (v1 - v2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin>>N>>M;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,M);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends