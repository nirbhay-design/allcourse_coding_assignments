#include <bits/stdc++.h>

using namespace std;

bool key(vector<int> &v1,vector<int> & v2) {
    if (v1[1] >= v2[1]) {
        return false;
    }
    return true;
}

int compatiblevalue(vector<vector<int>>& v,int i) {
    for (int tt=i-1; tt>=0; tt--) {
        if (v[tt][1] <= v[i-1][0]) {
            return tt;
        }
    }
    return -1;
}

int myfunction(vector<vector<int>> &v,int n) {
    if (n == 1) return v[n-1][2];
    int wt = v[n-1][2];
    int comptindex = compatiblevalue(v, n);
    wt += (comptindex!=-1)?myfunction(v,comptindex+1):0;
    int wt1 = myfunction(v, n-1);
    return (wt>wt1)?wt:wt1;
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

    int ans = myfunction(v,n);
    cout << ans;

    return 0;
}

/*
5
0 1 3 5 5
6 4 5 7 9
600 300 100 300 500

*/


