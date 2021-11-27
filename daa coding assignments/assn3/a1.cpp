#include <bits/stdc++.h>

using namespace std;

class vertex{
    public:
    int u,v,wt;
    vertex(int startV , int endV, int weight) {
        u = startV; v = endV;wt = weight;
    }
};

bool comparator(vertex * a,vertex * b) {
    if (a->wt >= b->wt) {
        return false;
    }
    return true;
}

class Solution{
    public:
    int n,e;
    vertex ** arr;
    int ** G;
    Solution() {
        cin >> n >> e;
        arr = new vertex*[e];
        for (int i =0;i<e;i++) {
            int u ,v,wt;cin>> u >> v >> wt;
            arr[i] = new vertex(u,v,wt);
        }

        G = new int*[n];
        for (int i =0;i<n;i++) {
            G[i] = new int[n];
            for (int j =0;j<n;j++) {
                G[i][j] = 0;
            }
        }
        sort(arr,arr+e,comparator);
    }
    bool cc(int nd,int par,int * vs) {
        vs[nd] = 1;
        for (int i =0;i<n;i++) {
            if (G[nd][i] != 0 && vs[i] ==0) {
                if (cc(i,nd,vs)) {
                    return true;
                }
            } else if (G[nd][i] != 0 && vs[i] ==1) {
                if (i != par) {
                    return true;
                }
            }
            
        }
        return false;
    }

    bool cycle(){
        int * vs = new int[n];
        for (int i =0;i<n;i++) {
            vs[i] = 0;
        }
        for (int i =0;i<n;i++) {
            if (vs[i] == 0) {
                if (cc(i,-1,vs)) {
                    return true;
                }
            }
        }
        return false;        
    }
    void solve() {
        vertex ** mst = new vertex*[n-1];
        int * vs = new int[n];
        for (int i =0;i<n;i++) {
            vs[i] = 0;
        }
        int t = 0;
        int finalans=0;
        for (int i=0;i<e;i++) {
            G[arr[i]->u][arr[i]->v] = arr[i]->wt;
            G[arr[i]->v][arr[i]->u] = arr[i]->wt;
            if (cycle()) {
                G[arr[i]->u][arr[i]->v] = 0;
                G[arr[i]->v][arr[i]->u] = 0;
                // cout << "cycle detected" << endl;
            } else {
                mst[t++] = arr[i];
                finalans += arr[i]->wt;
            }
        }
        cout << finalans << endl;
    }
};


int main(int argc , char * argv[]) {
    Solution * sol = new Solution();
    sol->solve();

}

/*
4
5
0 1 2
0 2 5
1 2 1
1 3 5
2 3 2

*/