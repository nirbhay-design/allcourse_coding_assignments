#include <bits/stdc++.h>
#define MAX_ADJ 1000

using namespace std;


class Solution{
    public:
    int n,e;
    int ** m;
    Solution() {
        cin >> n >> e;
        m = new int*[n];
        for (int i =0;i<n;i++) {
            m[i] = new int[n];
            for (int j =0;j<n;j++) {
                m[i][j] = 0;
            }
        }
        for (int i =0;i<e;i++) {
            int u ,v, wt;
            cin >> u >> v >> wt;
            m[u][v] = wt;
            m[v][u] = wt;
        }
    }
    void solve(int s) {
        vector<int> visited(n,0);
        vector<int> distance(n,INT_MAX);
        distance[s] = 0;
        int curmin=s;
        while (true) {
            visited[curmin] = 1;
            // cout << "visiting : " <<curmin << endl;
            for (int i =0;i<n;i++) {
                if (m[curmin][i]!=0 && !visited[i]) {
                    int tempdist = distance[i];
                    int checkdist = m[curmin][i] + distance[curmin];
                    if (checkdist < tempdist) {
                        distance[i] = checkdist;
                        // cout << "updating distance of : " << i << endl;
                    }
                    // distance[i] = (checkdist < tempdist)?checkdist:tempdist;
                }
            }
            int node=INT_MIN;
            int minn=INT_MAX;
            for (int i =0;i<n;i++) {
                if (!visited[i]) {
                    if (minn >= distance[i]) {
                        node = i;
                        minn = distance[i];
                    } 
                }
            }
            // cout << "min this time : " << node << endl;
            if (node == INT_MIN) {
                // cout << "breaking" << endl;
                break;
            } else {
                // cout << "updating curmin from : "<< curmin << " to node : "<< node << endl;
                curmin = node;
            } 
        }
        int ans=0;
        for (int i =0;i<n;i++) {
            ans += distance[i];
            cout << distance[i] << " ";
        }
        cout << endl;
        cout << 2*ans;
    }
};


int main(int argc , char * argv[]) {
    Solution * sol = new Solution();
    sol->solve(0);
}