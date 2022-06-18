// Problem Link - https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/1#

// Solution - Time Compexity - O(1)

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        long long s;
        s=N*(N+1)*(2*N+1);
        s/=6;
        return s;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
} 
