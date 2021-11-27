#include <bits/stdc++.h>

using namespace std;

vector<int> extract(string p) {
    int i = 0;
    vector<int> v;
    while (i < p.length()) {
        int asc = p[i] - '0';
        if (asc > 9 || asc < 0) {
            i++;
        } else {
            string sor = "";
            sor += p[i++];
            while (i < p.length() && p[i] != ' ') {
                sor += p[i++];
            }
            // cout << "pushsing: " << sor << endl;
            v.push_back(stoi(sor));
        }
    }
    // for (int i =0;i<v.size();i++) {
    //     cout << v[i] << " "; 
    // }
    // cout << endl;
    return v;
}


class solution{
    public:
    int n;
    vector<vector<int>> v;
    solution(){
        cin >> n;
        char m = getchar();
        for (int i =0;i<n;i++) {
            string poly;
            getline(cin,poly);
            vector<int> vv = extract(poly);
            v.push_back(vv);
        }
         
    }
    vector<int> solve2(vector<int> v1,vector<int> v2) {
        vector<int> v(v1.size()+v2.size()-1);
        for (int i =0;i<v1.size();i++) {
            for(int j =0;j<v2.size();j++) {
                v[i+j] += v1[i] * v2[j];
            }
        }
        return v;
    }

    void solve(){
        vector<int> repl = v[0];
        for (int i =1;i<v.size();i++) {
            repl = solve2(repl,v[i]);
        }
        for (int i =0;i<repl.size();i++) {
            cout << repl[i] << " ";
        }
    }
};


int main(int argc ,char * argv[]) {
    solution * sol = new solution();
    sol->solve();
    return 0;
}