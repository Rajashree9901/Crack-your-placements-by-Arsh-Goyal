// Problem link: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/#

// Solution

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>>str;
        int n=string_list.size();
        int a[n]={0};
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                vector<string> v;
                a[i]=-1;
                string s=string_list[i];
                v.push_back(s);
                sort(s.begin(),s.end());
                for(int j=i+1;j<n;j++)
                {
                    string p=string_list[j];
                    sort(p.begin(),p.end());
                    if(p==s)
                    {
                        v.push_back(string_list[j]);
                        a[j]=-1;
                    }
                }
                str.push_back(v);
            }
            
        }
        return str;
        
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
