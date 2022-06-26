// Problem - https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/#
// Solution - 
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        for(int i=0;i<9;i++)
        {
            map<int,int>m;
            for(int j=0;j<9;j++)
            {
                if(mat[i][j]!=0)
                {
                     m[mat[i][j]]++;
                     if( m[mat[i][j]]>1)
                         return 0;
                }
            }
        }
        for(int j=0;j<9;j++)
        {
            map<int,int>n;
            for(int i=0;i<9;i++)
            {
                if(mat[i][j]!=0)
                {
                     n[mat[i][j]]++;
                     if( n[mat[i][j]]>1)
                     return 0;
                }
            }
        }
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                map<int,int>mp;
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        if(mat[k][l]!=0)
                        {mp[mat[k][l]]++;
                        if(mp[mat[k][l]]>1)
                        return 0;}
                    }
                }
            }
        }
        
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
