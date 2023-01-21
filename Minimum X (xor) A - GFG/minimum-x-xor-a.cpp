//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:

  #define ll long long 

  int log_a_to_base_b(int a, int b)

{

    return (a > b - 1)

               ? 1 + log_a_to_base_b(a / b, b)

               : 0;

}

int mpow_normal(int base, int exp)

{ /*base%=mod;*/

    int result = 1;

    while (exp > 0)

    {

        if (exp & 1)

            result = ((int)result * base) /*% mod*/;

        base = ((int)base * base) /* % mod*/;

        exp >>= 1;

    }

    return result;

}

    int minVal(int a, int b) {

 int digits=max(log_a_to_base_b(a,2),log_a_to_base_b(b,2))+1;

int ones= __builtin_popcount(b);

vector<int>v1(digits,0),v2(digits,0);

 for(int bit=digits-1;bit>=0;bit--){

    if(((1<<bit)&a) ==0){

     v1[bit]=0;   

    }

    else {

        v1[bit]=1;

    }

     

 }

 for(int i=digits-1;i>=0;i--){

     if(v1[i]==1 and ones>0){

         v2[i]=1;

         --ones;

     }

 }

 for(int i=0;i<digits;i++){

     if(v1[i]==0 and ones>0){v2[i]=1; --ones;}

 }

 

 int j=0,sum=0;

 for(int i=0;i<digits;i++){

     sum+= v2[i]*(mpow_normal(2,j));

     ++j;

 }

 

 return sum;

 

    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends