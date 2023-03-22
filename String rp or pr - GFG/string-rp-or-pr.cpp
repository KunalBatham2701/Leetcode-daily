//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long int evaluate(char ch1, char ch2, int x, int y, string &s)
    {
       stack<int> st;
       long long int ans = 0;
       int n = s.length();
       for(int i = 0; i < n; i++)
       {
           if(!st.empty() && s[st.top()] == ch1 && s[i] == ch2){
               st.pop();
               ans += x;
           }
           else{
               st.push(i);
           }
       }
     
       long long a = 0, b = 0;
       while(st.size() > 1)
       {
           a = 0, b = 0;
           while(!st.empty() && (s[st.top()] == ch1 || s[st.top()] == ch2)){
               if(ch1 == s[st.top()]){
                   a += 1;
               }
               else{
                   b += 1;
               }
               st.pop();
           }
           if(!st.empty())
           st.pop();
           ans += min(a, b) * y;
       }
       return ans;
    }
public:
    long long solve(int x, int y, string S){
       
       if(x > y)
       return evaluate('p', 'r', x, y, S);
     return evaluate('r', 'p', y, x, S);
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends