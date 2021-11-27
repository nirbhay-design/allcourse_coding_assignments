#include <bits/stdc++.h>

using namespace std;


int main(int argc, char * argv[]) {

    int n;cin >> n;
    int * arr = new int[n];
    for(int i =0;i<n;i++) {
        cin >> arr[i];
    }
    int ** dp = new int*[n];
    for (int i =0;i<n;i++) {
        dp[i] = new int[n];

    }
    int overallmax = INT_MIN;
    for (int g = 0;g<n;g++) {
        int gg = g;
        for (int j =0;j<n-g;j++) {
            if (g == 0) {
                dp[j][gg] = arr[gg];
            } else {
                dp[j][gg] = arr[gg] * dp[j][gg-1];
            }
            if (overallmax < dp[j][gg]) {
                overallmax = dp[j][gg];
            }
            gg++;
        }
    }
    
    cout << overallmax << endl;
    for (int i =0;i<n;i++) {
        for (int j =0;j<n;j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}