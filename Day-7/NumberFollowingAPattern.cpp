// Problem link- https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#

// Solution - Using stack, Time complexity- O(n^2)


#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
       stack<int> st;
       int num=1;
       string p="";
       
       for(int i=0;i<S.length();i++)
       {
           if(S[i]=='I')
           {
               st.push(num);
               num++;
               while(!st.empty())
               {
                   int t;
                   t=st.top();
                   p+=to_string(t);
                   st.pop();
               }
           }
           else
           {
               st.push(num);
               num++;
           }
       }
       st.push(num);
       
       while(!st.empty())
       {
           p+=to_string(st.top());
           st.pop();
       }
       
       return p;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
 
