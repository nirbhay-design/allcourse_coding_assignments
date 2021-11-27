#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    int p,q,t;
    vector<vector<int>> v;
    solution() {
        cin >> p >> q >> t;
        v.resize(p);
        for (int i =0;i<p;i++) {
            v[i].resize(q);
            for (int j = 0;j<q;j++) {
                cin >> v[i][j];
            }
        }
    }

    void rotate(int i) {
        if (min(p,q)-2*i-1 < 0) {
            return;
        }        
        pair<int,int> tl = make_pair(i,i);
        pair<int,int> bl= make_pair(p-i,i);
        pair<int,int> tr = make_pair(i,q-i);
        pair<int,int> br = make_pair(p-i,q-i);

        if(min(p,q)-2*i -1 == 0) {
            // only one row/col
            if ((p - 2*i -1) == 0) {
                // horizontal
                reverse(v[i].begin()+i,v[i].begin()+q-i);
            } else if ((q-2*i -1) == 0) {
                // vertical;
                int repl = v[i][i];
                for (int j = i+1;j<(p-i);j++) {
                    int val =v[j][i];
                    v[j][i] = repl;
                    repl =val;
                }
                v[i][i] = repl;
            }
        }
        else {
            // cout << "entering here\n";
            // all 4 corners are available
            int repl = v[i][i];

            for (int j = i+1;j<(p-i);j++) {
                int val = v[j][i];
                v[j][i] = repl;
                repl = val;
            }
            // cout << "b\n";
            for (int j = i+1;j<(q-i);j++) {
                int val = v[p-i-1][j];
                v[p-i-1][j] = repl;
                repl =val;
            }
            // cout << "c\n";
            for (int j = p-i-2;j>=i;j--) {
                int val = v[j][q-i-1];
                v[j][q-i-1] = repl;
                repl = val;
            }
            // cout << "d\n";
            for (int j = q-i-2;j>=i;j--) {
                int val = v[i][j];
                v[i][j] = repl;
                repl = val;
            }

            // v[i][i] = repl;
            // cout << "e\n";

        }

        // for (int i =0;i<p;i++) {
        //     for (int j = 0;j<q;j++) {
        //         cout<<  v[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // rotate that part

        rotate(i+1);

    }
    void solve() {
        for (int i =0;i<t;i++) {
            rotate(0);
        }
        for (int i =0;i<p;i++) {
            for (int j = 0;j<q;j++) {
                cout<<  v[i][j] << " ";
            }
            cout << endl;
        }
    }
};



int main(int argc , char * argv[]) {
    solution *s = new solution();
    s->solve();
    
    return 0;
}

/*
4 4 2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16


*/