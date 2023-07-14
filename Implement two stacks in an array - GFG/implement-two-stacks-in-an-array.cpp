//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks
{
    int *a;
    int size;
    int top1, top2;
    int ans = 0;
    
    int p1 = 0, p2 = 99;
    
    public:
    
    twoStacks(int n=100)
    {
        size = n; 
        a = new int[n]; 
        top1 = -1; 
        top2 = size;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        top1 ++;
        a[top1] = x;
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        top2 --;
        a[top2] = x;
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1 < 0)
        return -1;
        
        ans = a[top1];
        a[top1] = 0;
        top1 --;
      
        return ans;
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(top2 >= 100)
       return -1;
       
       ans = a[top2];
       a[top2] = 0;
       top2 ++;
       return ans;}
};



//{ Driver Code Starts.

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;
        
        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
        	if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends