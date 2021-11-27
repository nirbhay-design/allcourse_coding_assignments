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
    Solution() {
        cin >> n >> e;
        arr = new vertex*[e];
        for (int i =0;i<e;i++) {
            int u ,v,wt;cin>> u >> v >> wt;
            arr[i] = new vertex(u,v,wt);
        }
        sort(arr,arr+e,comparator);
    }

    int find(int x,int * set){
        return (set[x] ==x)?x:find(set[x],set);
    }
    void solve() {
        vertex ** mst = new vertex*[n-1];

        int * set = new int[n];
        for(int i = 0;i<n;i++){
            set[i] = i;
        }
        int mstptr = 0;
        int finalans = 0;
        int i = 0;
        while(mstptr!= n-1){
            vertex * curedge = arr[i];
            int source_parent = find(curedge->u,set);
            int dest_parent = find(curedge->v,set);
            if(source_parent!=dest_parent){//means a cycle is not forming
                mst[mstptr++] = curedge;
                set[source_parent] = dest_parent;
                finalans += curedge->wt;
            }
            i++;
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