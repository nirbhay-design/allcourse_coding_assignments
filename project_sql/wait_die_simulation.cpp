#include <bits/stdc++.h>

using namespace std;

void dfs(int i ,vector<vector<int>> G,vector<int> &vis,vector<int> ts){
    vis[i] = 1;
    for (int j = 0;j<G.size();j++){
        if(G[i][j] && vis[j]==1){
            if(ts[i] > ts[j]) {
                cout << "transaction " << i << " returning\n";
            } else{
                cout << "transaction " << i << " will wait\n";
            }
        } else if(G[i][j] && !vis[j]){
            dfs(j,G,vis,ts);
        }
    }
    vis[i] = 2;
}


int main(int argc, char * argv[]){
    srand(time(NULL));
    vector<vector<int>> G = {{0,1,0,0}, {0,0,1,0}, {0,0,0,1}, {1,0,0,0}};
    vector<int> ts = {rand()%5,rand()%5+1,rand()%5,rand()%5};
    vector<int> vis(4,0);
    dfs(0,G,vis,ts);
}