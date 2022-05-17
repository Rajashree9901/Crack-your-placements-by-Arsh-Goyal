// Problem link-https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/

// Solution 1: Using Brute force- O(n^2) approch


#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<k)
            c++;
            int mul=a[i];
            for(int j=i+1;j<n;j++)
            {
                mul=mul*a[j];
                if(mul<k)
                c++;
                else
                break;
            }
        }
        return c;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}


// Solution 2: Using Sliding window protocol- O(n) approach


#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        if(k<=1)
        return 0;
        
        int c=0;
        long long m=1;
        
        int l=0,r=0;
        
        while(r<n)
        {
            m*=a[r];
            while(m>=k and l<r)
            {
                m/=a[l];
                l++;
            }
            
            if(m<k)
            {c+=r-l+1;}
            r++;
        }
        return c;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
