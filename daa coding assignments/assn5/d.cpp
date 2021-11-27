#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    int n1,n2;
    vector<int> v1,v2;
    solution(){
        cin >> n1;
        v1.resize(n1);
        for (int i =0;i<n1;i++) {
            cin >> v1[i];
        }
        cin >> n2;
        v2.resize(n2);
        for (int i =0;i<n2;i++) {
            cin >> v2[i];
        }
    }
    void solve(){
        vector<int> v;
        int p1 = 0,p2 = 0;
        while (p1 < n1 && p2 < n2) {
            if (v1[p1] > v2[p2]) {
                v.push_back(v2[p2]);
                p2++;
            } else if (v1[p1] == v2[p2]) {
                v.push_back(v2[p2]);
                v.push_back(v2[p2]);
                p1++;p2++;
            } else {
                v.push_back(v1[p1]);
                p1++;
            }
        }
        while (p1 < n1) {
            v.push_back(v1[p1++]);
        }
        while (p2 < n2) {
            v.push_back(v2[p2++]);
        }
        int val = (n1 + n2) /2;
        float ans;
        if ((n1 + n2) % 2 ==0) {
            ans = (v[val] + v[val-1])/2.0;  
        } else {
            ans = v[val];
        }
        cout << ans;
    }
};


int main(int argc, char * argv[]) {
    
    solution * sol = new solution();
    sol->solve();
    
    return 0;
}