// Problem Link - https://leetcode.com/problems/longest-mountain-in-array/

// Solution -  By traversing the array once, Time Complexity - O(n)

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3)
            return 0;
        int i=0;
        int m=0;
        while(i<arr.size()-1)
        {
            int in=0,de=0;
            while((i+1)!=arr.size() and arr[i]>=arr[i+1])
                i++;
            
            while((i+1)!=arr.size() and arr[i+1]>arr[i])
            {
                in++;
                i++;
            }
            
            while((i+1)!=arr.size() and arr[i+1]<arr[i])
            {
                de++;
                i++;
            }
            
            if(in==0 or de==0)
                m=m;
            else
                m=max(m,in+de+1);
            
        }
        
        return m;
    }
};
