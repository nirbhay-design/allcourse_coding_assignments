#include <bits/stdc++.h>

using namespace std;

class solution{
    public:
    int n;
    vector<int> v;
    solution(){
        cin >> n;
        v.resize(n);
        for(int i = 0;i<n;i++){
            cin >> v[i];
        }        
    }
    int solve(){
        vector<int> piles;
        piles.push_back(v[0]);
        for (int i = 1;i<n;i++){
            int sz = piles.size();
            bool placed = false;
            for (int j = 0;j<sz;j++){
                if (piles[j] >= v[i]){
                    piles[j] = v[i];
                    placed = true;
                    break;
                }
            }
            if (!placed){
                piles.push_back(v[i]);
            }
        }

        return piles.size();

    }
};


int main(int argc, char * argv[]){
    solution * sol = new solution();
    int ans = sol->solve();
    cout << ans;
    return 0;
}