//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	vector<int>mt;
	vector<bool>used;
	
	
	bool try_kunh(int u, vector<vector<int>>&G){
	    for (int v = 0; v < G[0].size(); v++){
	        if (G[u][v] && !used[v])
	        {
	            used[v] = true;
	            if (mt[v] < 0 || try_kunh(mt[v], G))
	            {
	                mt[v] = u;
	                return true;
	            }
	        }
	    }
    return false;
	}
	int maximumMatch(vector<vector<int>>&G){
	    
		int m = G.size(), n = G[0].size(), ans=0;
		
		mt.assign(max(n,m), -1);
		
		for(int i = 0; i < m; i++){
			used.assign(max(n,m), false);

			if(try_kunh(i, G))
				ans++;
			//for(auto it:mt) cout<<it<<" ";
			//cout<<"\n";
			
		}
		return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends