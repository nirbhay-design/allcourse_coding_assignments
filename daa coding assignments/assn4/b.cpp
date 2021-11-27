#include <bits/stdc++.h>

using namespace std;

// logic find the longest palindromic subsequence and then subtract it from the length of the string 

class Solution{
    public:
    string s;
    vector<vector<int>> dp;
    Solution(){
        int n;cin >>n;
        cin >> s;
        dp.resize(s.length());
        for (int i =0;i<s.length();i++) {
            dp[i].resize(s.length());
        }
    }
    void getMinchar() {
        // cout << "e" << endl;
        for (int g = 0;g<s.length();g++) {
            int gg =g;
            for (int j = 0;j<s.length()-g;j++) {
                if (g == 0) {
                    // cout << "a" << endl;
                    dp[j][gg++] = 1; 
                } else if (g == 1) {
                    // cout << "b" << endl;
                    dp[j][gg] = (s[j] == s[gg])?2:1;
                    gg++;
                } else {
                    // cout << "c" << endl;
                    dp[j][gg] = (s[j] == s[gg])?(2+dp[j+1][gg-1]):max(dp[j+1][gg],dp[j][gg-1]);
                    gg++;
                }
            }
        }
        cout << (s.length()-dp[0][s.length()-1]);
    }
};


int main(int argc , char * argv[]) {
    Solution * sol = new Solution();
    sol->getMinchar();
    return 0;
}