// Problem link-https://leetcode.com/problems/ugly-number-ii/

// Solution- O(n) Approach using sets
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        
        s.insert(1);
        set<long long>::iterator itr;
        for(itr=s.begin();itr!=s.end();itr++)
        {
            s.insert((*itr) * 2);
            s.insert((*itr)*3);
            s.insert((*itr)*5);
            if(s.size()>n*2)
                break;
        }
        int c=0;
        for(itr=s.begin();itr!=s.end();itr++)
        {
            c++;
            if(c==n)
                break;
        }
        
        return *itr;
    }
};
