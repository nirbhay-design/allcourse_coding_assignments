#include <bits/stdc++.h>

using namespace std;
class Solution{
    public:
    int n;
    string s;
    int ** dp;
    Solution(int nn,string ss) {
        n = nn;
        s = ss;
        dp = new int*[n];
        for (int i =0;i<n;i++) {
            dp[i] = new int[n];
            for (int j =0;j<n;j++) {
                dp[i][j] = -1; 
            }
        }
    }
    int mincharreq(int i,int j) {
        if (i > j) {
            // dp[i][j] = 0;
            return 0; 
        }
        if (i == j) {
            return (dp[i][j] = 1);
        }
        
        if (dp[i][j] != -1) {
            // cout << "returning" << endl;
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            return (dp[i][j] = 2+mincharreq(i+1,j-1));
        }
        
        return (dp[i][j] = max(mincharreq(i+1,j),mincharreq(i,j-1)));

    }
    void solve() {
        cout << n-mincharreq(0,n-1);
        // for (int i =0;i<n;i++) {
        //     for (int j =0;j<n;j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }

};
int main(int argc ,char * argv[]) {
    int n;
    string s;
    cin >> n >> s;
    
    Solution * sol = new Solution(n,s);
    sol->solve();
    return 0;
}