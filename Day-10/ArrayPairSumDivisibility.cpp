// Probllem Link - https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#

// Solution - Using unorderd map, Time Complexity - O(n)


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()%2!=0)
        return false;
        
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]%k;
            m[nums[i]]++;
        }
        
        if(m[0]%2!=0)
        return false;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {if(m[nums[i]]!=m[k-nums[i]])
            return false;}
        }
        
        return true;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  
