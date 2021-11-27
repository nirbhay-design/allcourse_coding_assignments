#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<int,int> & v1,pair<int,int> &v2) {
    if (v1.first >= v2.first) {
        return false;
    }
    return true;
}

int main(){
    int n ; cin >> n ;
    vector<pair<int,int>> v;
    for(int i =0;i<n;i++) {
        int x,y;
        cin >> x >> y ;
        v.push_back(make_pair(x,y));
    }
    int classes ; cin>> classes;

    int ans =1;
    vector<int> assn(n,-1);
    
    sort(v.begin(),v.end(),comparator);
    assn[0] = ans;
    for (int i=1;i<n;i++) {
        unordered_set<int> st;
        int ind;
        bool found=false;
        for (int j = i-1;j>=0;j--) {
            if ((v[i].first < v[j].second) && (v[j].first < v[i].second)) {//overlap
                st.insert(assn[j]);
            }
        }

        for (int tt=1;tt<=ans;tt++) {
            if (st.count(tt) == 0) {
                ind = tt;
                found =true;
                break;
            }
        }
        assn[i] = (found) ? ind : ++ans;
    }

    // for (int i =0;i<assn.size();i++) {
    //     cout << assn[i] << " ";
    // }
    // cout << endl;
    string value = (ans <= classes) ? "Yes" : "No";
    cout << value;// << endl;
    // cout << ans << endl;

    // code 
    return 0;
}

/*
10
1 2
1 3
1 4
2 4
3 5
4 6
4 6
6 7
6 8
6 8
5

*/