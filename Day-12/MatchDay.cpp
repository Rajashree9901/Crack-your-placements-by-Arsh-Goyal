// Problem link - https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/#

// Solution - Using Sliding Window, Time Complexity- O(n*k)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> a, int n, int k) {

        vector<int>v(n-k+1,-1);
        if(n<k)
        return v;
        
        int max=0,j=0,pos;
        
        for(int i=0;i<k;i++)
        {
            if(max<a[i])
            {
                max=a[i];
                pos=i;
            }
        }
        
        v[j++]=max;
        
        for(int i=k;i<n;i++)
        {
            if(max>a[i] and pos>=j)
            {
                v[j]=max;
                j++;
            }
            else if(max<a[i] and pos>=j) 
            {
                max=a[i];
                v[j]=max;
                j++;
                pos=i;
            }
            else
            {
                if(max<a[i])
                {
                    max=a[i];
                    pos=i;
                    v[j]=max;
                    j++;
                }
                else
                {
                    max=0;
                    for(int p=i;p>i-k;p--)
                    {
                        if(max<a[p])
                        {
                            max=a[p];
                            pos=p;
                        }
                    }
                    v[j]=max;
                    j++;
                }
            }
        }
    }
};

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
} 
