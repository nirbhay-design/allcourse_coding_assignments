#include <bits/stdc++.h>
#define MAX_ADJ 1000

using namespace std;
class vertex{
    public:
    int counter,dist;
    int * adjlist;
    vertex() {
        counter = 0;
        dist = INT_MAX;
        adjlist = new int[MAX_ADJ];
    }
};

class Solution{
    public:
    int n,e;
    vertex ** arr;
    int ** m;
    Solution() {
        cin >> n >> e;
        arr = new vertex*[n];
        m = new int*[n];
        for (int i =0;i<n;i++) {
            m[i] = new int[n];
            arr[i] = new vertex();
        }
        for (int i =0;i<e;i++) {
            int u ,v, wt;
            cin >> u >> v >> wt;
            m[u][v] = wt;
            m[v][u] = wt;
            arr[u]->adjlist[arr[u]->counter++] = v;
            arr[v]->adjlist[arr[v]->counter++] = u;
        }
    }
    void solve(int s) {
        arr[s]->dist = 0;
        int * visit = new int[n];
        for(int i = 0;i<n;i++){
            visit[i] = 0;
        }
        int * distance = new int[n];
        for(int i = 0;i<n;i++){
            distance[i] = INT_MAX;
        }
        distance[s] = 0;
        int p = s;
        for(int i = 0;i<n;i++){// just running loop n times
            for(int j = 0;j<arr[p]->counter;j++){
                int tom = arr[p]->adjlist[j];
                if(visit[tom] == 0){
                    int distvalue = m[p][tom] + arr[p]->dist;
                    if(distvalue < arr[tom]->dist){
                        arr[tom]->dist = distvalue;
                        distance[tom] = distvalue;
                    }
                }
            }
            visit[p] = 1;
            int min = -1;
            int minval = INT_MAX;
            for(int k = 0;k<n;k++){
                if(visit[k] == 0){
                    if(distance[k] < minval){
                        min = k;
                        minval = distance[k];
                    }
                }
            }
            if(min == -1){
                break;
            }
            p = min;

        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += distance[i];
        }

        cout << 2*ans << endl;
    }
};


int main(int argc , char * argv[]) {
    Solution * sol = new Solution();
    sol->solve(0);
}