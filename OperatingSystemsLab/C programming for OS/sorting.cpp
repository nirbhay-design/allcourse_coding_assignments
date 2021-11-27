#include <bits/stdc++.h>


using namespace std;

bool comparator(pair<int,int> &p1,pair<int,int> &p2){
    if (p1.second > p2.second) {
        return false;
    } else if (p1.second == p2.second ) {
        if (p1.first < p2.first ) {
            return false;
        }
    }
    return true;


}

bool comparator1(pair<int,int> &p1 , pair<int,int> &p2){
    if (p1.first <= p2.first) {
        return true;
    }
    return false;

}

int main(){
    int n ;cin >> n;
    vector<pair<int ,int >> v;
    for (int i =0;i<n;i++) {
        int u,u2;
        cin >> u >> u2;
        v.emplace_back(make_pair(u,u2));        
    }

    sort(v.begin(),v.end(),comparator1);
    
    int ans = 0;

    while (v.size()>0){
        int val = v.size();
        pair<int,int> comp = v[0];
        ans++;
        int i =0;
        while (i<val){
            if (comp.first <= v[i].first && v[i].first < comp.second && (comp.second <= v[i].second || comp.second >= v[i].second)) {
                v.erase(v.begin()+i);
                val--;
            } else {
                i++;
            }
        }
    }
    cout << ans << endl;
    return 0;   
}