#include <bits/stdc++.h>

using namespace std;

bool key(vector<int> &v1,vector<int> & v2) {
    if (v1[1] >= v2[1]) {
        return false;
    }
    return true;
}

int main(){

    int n;cin >> n;

    vector<vector<int>> v(n,vector<int>(3));

    for (int i =0;i<n;i++) {
        cin >> v[i][0];
    }

    for (int i =0;i<n;i++) {
        cin >> v[i][1];
    }

    for (int i =0;i<n;i++) {
        cin >> v[i][2];
    }

    // for (int i =0;i<n;i++) {
    //     cout << v[i][0] <<" " << v[i][1]<<" " << v[i][2] << endl;
    // }
    
    sort(v.begin(),v.end(),key);
    // cout << "\n";
    
    // for (int i =0;i<n;i++) {
    //     cout << v[i][0] <<" " << v[i][1]<<" " << v[i][2] << endl;
    // }

    vector<vector<vector<int>>> ans;
    while (v.size() > 0) {
        vector<int> temp = v[0];
        ans.push_back({temp});
        int sz = ans.size();
        for (int i =0;i<sz;i++) {
            bool comp=true;
            for (auto values:ans[i]) {
                if (temp[1] <= values[0] || values[1] <= temp[0]) {
                    continue;
                } else {
                    comp = false;
                }
            }
            if (comp) {
                ans.push_back(ans[i]);
                ans[i].push_back(temp);
            }
        }

        v.erase(v.begin()+0);
    }

    // for (int i = 0;i<ans.size();i++) {
    //     for (int j =0;j<ans[i].size();j++) {
    //         cout << "("<<ans[i][j][0] << ", " << ans[i][j][1] << "), ";
    //     }
    //     cout << endl;
    // }
    
    int maxwt = INT_MIN;
    for (int i = 0;i<ans.size();i++) {
        int wt= 0;
        for (int j =0;j<ans[i].size();j++) {
            wt += ans[i][j][2];
        }
        maxwt = max(wt,maxwt);
    }

    cout << maxwt << endl;
    return 0;
}

/*
5
0 1 3 5 5
6 4 5 7 9
600 300 100 300 500

7
0 1 3 5 5 0 9
6 4 5 7 9 1 11
600 300 100 300 500 5000 1000
*/