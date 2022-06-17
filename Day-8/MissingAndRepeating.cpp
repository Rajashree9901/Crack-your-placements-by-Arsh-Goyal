// Problem Link - https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/#

// Solution 1 - Using sorting, Time Complexity - O(nlogn)

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int b[2];
        sort(arr,arr+n);
        
        if(n==1)
        b[0]=1;
        else
        {
            int s=0;
            for(int i=0;i<n;i++)
            {
                s+=arr[i];
            }
            for(int i=0;i<n-1;i++)
            {
                if(arr[i]^arr[i+1]==0)
                b[0]=arr[i];
            }
            int p=(n*(n-1))/2;
            b[1]=p-s+b[0];
        }
        return b;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
