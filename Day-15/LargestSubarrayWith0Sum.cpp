// Problem link- https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Solution - Using unordered map, Time Complexity - O(n) 

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int l=0,sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            if(sum==0)
            l=i+1;
            else
            {
                if(mp.find(sum)!=mp.end())
                l=max(l,i-mp[sum]);
                else
                mp[sum]=i;
            }
        }
        return l;
        
    }
};
