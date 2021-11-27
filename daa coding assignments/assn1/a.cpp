#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,e ; cin >> n >> e;

    vector<vector<int>> G(n,vector<int>(n,0));

    for(int i =0;i<e;i++){
        int u,v ; cin >> u >> v;
        G[u-1][v-1] = 1;
        G[v-1][u-1] = 1;
    }

    // for (int i=0;i<n;i++){
    //     for(int j = 0;j<n;j++){
    //         cout << G[i][j] << " " ;        
    //     }
    //     cout << endl;
    // }

    // vertex start from 0 -> n-1;

    vector<int> visited(n,0);

    int startNode = 0;
    int island = 0;
    int grpnumber=2;

    while(startNode < n){
        if(visited[startNode] != 0) {startNode++;continue;}

        queue<int> q;
        q.push(startNode);
        while(!q.empty()){
            int nodeval = q.front();
            q.pop();
            visited[nodeval] = 1;

            for (int i =0;i<n;i++){
                if(G[nodeval][i] == 1 && visited[i] == 0){
                    q.push(i);
                }
            }
        }

        startNode++;

        int visitednodes=0;
        for(int i =0;i<n;i++){
            if(visited[i] == 1 ){
                visited[i] = grpnumber;
                visitednodes++;
            }
        }

        if(visitednodes == n){
            island++;
            break;
        }

        island++;
        grpnumber++;

    }

    cout << island << endl;

    for(int i =0;i<n;i++){
        if(visited[i] == 2){
            cout << i+1 << " ";
        }
    }


    return 0;
}

/*
5
3
1 2
3 2
4 5

*/