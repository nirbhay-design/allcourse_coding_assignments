#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<int,int> & p1,pair<int,int> & p2) {
    return (p1.second <= p2.second);
}

// bool check(pair<int,int> p1,pair<int,int> p2) {
//     if ( (p1.first < p2.first || p1.first >= p2.first) && (p1.second > p2.second || p1.second <= p2.second) && (p1.second > p2.first)) {
//         return true;
//     }
//     return false;
// }

int main(int argc , char * argv[]) {
    int n; cin >> n;

    vector<pair<int,int>> v;
    for (int i =0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(),v.end(),comparator);

    int ans = 0;

    while (v.size()>0){
        int val = v.size();
        pair<int,int> comp = v[0];
        ans++;
        int i =0;
        while (i<val){
            if ((v[i].first < comp.second) && (comp.first < v[i].second)) {
                v.erase(v.begin()+i);
                val--;
            } else {
                i++;
            }
        }
    }
    cout << ans << endl;



}