// Problem link- https://practice.geeksforgeeks.org/problems/run-length-encoding/1/#

// Solution- O(n) Approch

#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}

string encode(string src)
{     
  //Your code here 
  string s="";
  for(int i=0;i<src.length();i++)
  {
      int c=0;
      while(src[i]==src[i+1])
      {
          c++;
          i++;
      }
      s+=src[i];
      s+=to_string(c+1);
  }
  return s;
}     
 
