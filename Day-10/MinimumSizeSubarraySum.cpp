// Problem link - https://leetcode.com/problems/minimum-size-subarray-sum/

// Solution - Using two pointer, Time Complexity - O(n)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,m=INT_MAX,s=0;
        int i=0,j=0;
        sum+=nums[i];
        
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
        }
        if(s<target)
            return 0;
        
        while(j<nums.size() and i<=j)
        {
            while(j<nums.size() and sum<target)
            {
                j++;
                if(j==nums.size())
                    break;
                sum+=nums[j];
            }
            m=min(m,j-i+1);
            sum=sum-nums[i];
            i++;
        }
        return m;
    }
};
