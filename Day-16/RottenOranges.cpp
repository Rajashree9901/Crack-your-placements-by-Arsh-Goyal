// Problem link - https://leetcode.com/problems/rotting-oranges/

// Solution - Approach- BFS traversal, Time Complexity-O(n^2)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()<1)
            return -1;
        
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        int c=-1;
        
        while(!q.empty())
        {
            int s=q.size();
            c++;
            for(int i=0;i<s;i++)
            {
                pair<int,int>p=q.front();
                q.pop();
                int k=p.first;
                int l=p.second;
                
                if(l+1<n and grid[k][l+1]%2!=0)
                {
                    q.push({k,l+1});
                    grid[k][l+1]=2;
                }
                if(k+1<m and grid[k+1][l]%2!=0)
                {
                    q.push({k+1,l});
                    grid[k+1][l]=2;
                }
                if(k-1>=0 and grid[k-1][l]%2!=0)
                {
                    q.push({k-1,l});
                    grid[k-1][l]=2;
                }
                if(l-1>=0 and grid[k][l-1]%2!=0)
                {
                    q.push({k,l-1});
                    grid[k][l-1]=2;
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]%2!=0)
                    return-1;
            }
        }
        
        if(c!=-1)
        return c;
        else
            return 0;
    }
};
