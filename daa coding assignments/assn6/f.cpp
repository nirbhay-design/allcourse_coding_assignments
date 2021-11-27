#include <bits/stdc++.h>

using namespace std;

class solution{
    public:
    int n;
    vector<int> v;
    solution(){
        cin >> n;
        v.resize(n);
        for (int i =0;i<n;i++){
            cin>>v[i];
        }
    }
    int solve(){
        vector<vector<int>> dp(n,vector<int>(n));
        int ans = 0;
        for (int g = 0;g<n;g++) {
            int gg = g;
            for (int j =0;j<n-g;j++) {
                if (g == 0) {
                    dp[j][gg] = v[gg];
                } else {
                    dp[j][gg] = min(dp[j][gg-1],dp[j+1][gg]);
                }
                ans += dp[j][gg];
                gg++;
            }
        }
        return ans;
    }
};


int main(int argc, char * argv[]){
    solution *sol = new solution();
    int ans = sol->solve();
    cout << ans;
    return 0;
}