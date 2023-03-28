//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends
//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
class Solution{
    public:
    
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
        long long ans = 0;
        unordered_map<int, int> hash;
        int mid = n;
        while(1){
            int low = 0, high = mid-1;
            
            int cost = -1; 
            while(low <= high){
                mid = (low+high)/2;
                
                
                //changes here
                int curCost;
                if(hash.count(mid))
                    curCost = hash[mid];
                else{
                    curCost = shop.get(mid);
                    hash[mid] = curCost;
                }
                //
                
                
                if(curCost > cost && curCost <= k){
                    cost = curCost; 
                    low = mid+1;
                }
                else
                    high = mid-1;
            }
            
            if(cost == -1 || cost > k) 
                break;                 
            
            ans += k/cost;
            k %= cost;     
        }
    
        return ans;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends