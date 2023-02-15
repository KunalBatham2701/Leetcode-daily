//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    void dfs( int i , int j , vector<vector<int>>&O , vector<vector<int>>&vis , vector<vector<int>>&mat )

    {

        vis[i][j] = 1 ;

        

        int dr[4] = { -1 , 1 , 0 , 0 } ;

        int dc[4] = { 0 , 0 , -1 , 1 } ;

        

        for( int k = 0 ; k < 4 ; k++ )

        {

            int r = i + dr[k] ;

            int c = j + dc[k] ;

            

            if( r < mat.size() && r >= 0 && c < mat[0].size() && c >= 0 )

            {

                if(!vis[r][c] && mat[r][c] >= mat[i][j] )

                {

                    O[r][c] = 1 ;

                    dfs( r , c , O , vis , mat ) ;

                }

            }

        }

    }

    int water_flow(vector<vector<int>> &mat,int N,int M){

    // Write your code here.

    

       vector<vector<int>>A( N , vector<int>(M , 0 )) ;

       vector<vector<int>>I( N , vector<int>(M , 0 )) ;

       vector<vector<int>>vis( N , vector<int>(M , 0 )) ;

       vector<vector<int>>vis1( N , vector<int>(M , 0 )) ;

       

       // starting dfs from indian ocean from top side 

       for( int i = 0 ; i < M ; i++ )

       {

           if(!vis[0][i])

           {

               I[0][i] = 1 ;

               dfs( 0 , i , I , vis , mat ) ;

           }

       }

       

       

       // starting dfs from indian ocean from left side 

       for( int i = 0 ; i < N ; i++ )

       {

           if(!vis[i][0])

           {

               I[i][0] = 1 ;

               dfs( i , 0 , I , vis , mat ) ;

           }

       }

       

       

       

        // starting dfs from Arabian ocean from bottom side 

       for( int i = 0 ; i < M ; i++ )

       {

           if(!vis1[N-1][i])

           {

               A[N-1][i] = 1 ;

               dfs( N-1 , i , A , vis1 , mat ) ;

           }

       }

       

       

       // starting dfs from Arabian ocean from right side  

       for( int i = 0 ; i < N ; i++ )

       {

           if(!vis1[i][M-1])

           {

               A[i][M-1] = 1 ;

               dfs( i , M-1 , A , vis1 , mat ) ;

           }

       }

       

       int count = 0 ;

       

       for( int i = 0 ; i < N ; i++ )

       {

           for( int j = 0 ; j < M ; j++ )

           {

               if( I[i][j] && A[i][j] )

               {

                   count++ ;

               }

           }

       }

       

       return count ;

       

       

       

       

       

    

    }

};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends