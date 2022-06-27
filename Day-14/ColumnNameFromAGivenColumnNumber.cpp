// Problem link- https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/#
// Solution - O(n) approach

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        vector<int>v;
        string s="";
        while(n>0)
        {
            v.push_back(n%26);
            n=n/26;
        }
        for(int i=0;i<v.size();i++)
        {
            if(i==v.size()-1 and v[i]==0)
            i++;
            
            if(v[i]==0)
            {
                v[i]=26;
                v[i+1]-=1;
            }
            char c=(char)(v[i]+64);
            s.push_back(c);
        }
        reverse(s.begin(),s.end());
        
        return s;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends
